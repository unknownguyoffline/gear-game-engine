#include "renderer/FrameBuffer.hpp"
#include <glad/glad.h>
#include <iostream>

void FrameBuffer::Create(const glm::uvec2 &size)
{
    glGenFramebuffers(1, &mId);
    mSize = size;
}

void FrameBuffer::Select()
{
    glBindFramebuffer(GL_FRAMEBUFFER, mId);
}

void FrameBuffer::Deselect()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Texture FrameBuffer::GetTexture()
{
    Select();
    Texture texture(nullptr, mSize, RGB);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.GetId(), 0);
    if (glCheckFramebufferStatus(mId) != GL_FRAMEBUFFER_COMPLETE)
    {
        printf("Error: frame buffer not complete\n");

        auto glstatus = glGetError();
        if (glstatus != GL_NO_ERROR)
        {
            std::cout << "Error in GL call: " << glstatus << std::endl;
        } 
    }
    return texture;
}

uint32_t FrameBuffer::mSelectedId = 0;
