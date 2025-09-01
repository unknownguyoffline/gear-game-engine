#include "renderer/VertexBuffer.hPp"
#include "Macro.hpp"
#include <glad/glad.h>

uint32_t VertexBuffer::mSelectedId = UINT_MAX;

inline GLenum glVertexUsage[] = {GL_STATIC_DRAW, GL_DYNAMIC_DRAW};

// clang-format off

GLenum glType[] = 
{
    GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT,
    GL_INT, GL_INT, GL_INT, GL_INT,
};

GLint glElementCount[] = 
{
	1,2,3,4,
	1,2,3,4
};

GLsizei glSize[] = 
{
	sizeof(GLfloat),2 * sizeof(GLfloat),3 * sizeof(GLfloat),4 * sizeof(GLfloat),
	sizeof(GLint),  2 * sizeof(GLint),  3 * sizeof(GLint),  4 * sizeof(GLint)
};

// clang-format on

void VertexBuffer::Create(GraphicBufferUsage usage)
{
    if (mId != UINT32_MAX)
        glDeleteBuffers(1, &mId);
    glGenBuffers(1, &mId);
    assert(mId != UINT_MAX);
    mUsage = usage;
}

void VertexBuffer::Create(size_t size, void *data, GraphicBufferUsage usage)
{
    if (mId != UINT32_MAX)
        glDeleteBuffers(1, &mId);
    glGenBuffers(1, &mId);
    glBindBuffer(GL_ARRAY_BUFFER, mId);
    glBufferData(GL_ARRAY_BUFFER, size, data, glVertexUsage[usage]);
    mUsage = usage;
}

void VertexBuffer::SetData(size_t size, void *data)
{
    assert(mId != UINT_MAX);
    assert(size != 0);
    glBindBuffer(GL_ARRAY_BUFFER, mId);
    glBufferData(GL_ARRAY_BUFFER, size, data, glVertexUsage[mUsage]);
    mCapacity = size;
    mSize = size;
}

void VertexBuffer::SubData(size_t size, void *data, size_t offset)
{
    assert(mId != UINT_MAX);
    assert((size + offset) <= mCapacity);
    assert(size != 0);
    glBindBuffer(GL_ARRAY_BUFFER, mId);
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
    mSize = size + offset;
}

void VertexBuffer::Select() const
{
    // if (mSelectedId == mId)
    //     return;
    assert(mId != UINT_MAX);
    size_t offset = 0;
    glBindBuffer(GL_ARRAY_BUFFER, mId);
    for (int i = 0; i < mLayout.size(); i++)
    {
        assert(mStride != 0);
        LayoutType type = mLayout[i];
        glEnableVertexAttribArray(i);
        GL_FLOAT;
        glVertexAttribPointer(i, glElementCount[type], glType[type], GL_FALSE, mStride, (void *)offset);
        offset += glSize[type];
    }
    mSelectedId = mId;
}

void VertexBuffer::Deselect() const
{
    assert(mId != UINT_MAX);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    mSelectedId = UINT32_MAX;
}

size_t VertexBuffer::GetSize() const
{
    assert(mId != UINT_MAX);
    return mSize;
}

size_t VertexBuffer::GetCapacity() const
{
    assert(mId != UINT_MAX);
    return mCapacity;
}
uint32_t VertexBuffer::GetStride() const
{
    return mStride;
}

void VertexBuffer::AddLayout(LayoutType type)
{
    mLayout.push_back(type);
    mStride += glSize[type];
}
void VertexBuffer::ClearLayout()
{
    mLayout.clear();
}
