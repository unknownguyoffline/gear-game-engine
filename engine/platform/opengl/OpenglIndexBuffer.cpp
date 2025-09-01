#include "renderer/IndexBuffer.hpp"
#include "Macro.hpp"
#include <glad/glad.h>

uint32_t IndexBuffer::mSeletedId = UINT32_MAX;

inline GLenum glVertexUsage[] = {GL_STATIC_DRAW, GL_DYNAMIC_DRAW};

void IndexBuffer::Create(GraphicBufferUsage usage)
{
    if (mId != UINT32_MAX)
        glDeleteBuffers(1, &mId);
    mUsage = usage;
    glGenBuffers(1, &mId);
    assert(mId != UINT_MAX);
}
void IndexBuffer::Create(size_t size, void *data, GraphicBufferUsage usage)
{
    Create(usage);
    SetData(size, data);
}

void IndexBuffer::SetData(size_t size, void *data)
{
    assert(mId != UINT_MAX);
    assert(size != 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, glVertexUsage[mUsage]);
    mCapacity = size;
    mSize = size;
    mSeletedId = mId;
}

void IndexBuffer::SubData(size_t size, void *data, size_t offset)
{
    assert(mId != UINT_MAX);
    assert((size + offset) <= mCapacity);
    assert(size != 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, size, data);
    mSize = size + offset;
}

void IndexBuffer::Select() const
{
    // if (mSeletedId == mId)
    //     return;
    assert(mId != UINT_MAX);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
    mSeletedId = mId;
}

void IndexBuffer::Deselect() const
{
    assert(mId != UINT_MAX);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    mSeletedId = UINT32_MAX;
}

size_t IndexBuffer::SetSize() const
{
    assert(mId != UINT_MAX);
    return mSize;
}

size_t IndexBuffer::GetCapacity() const
{
    assert(mId != UINT_MAX);
    return mCapacity;
}
