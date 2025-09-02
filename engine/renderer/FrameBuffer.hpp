#pragma once 
#include "renderer/Texture.hpp"

class FrameBuffer
{
  public:
    void Create(const glm::uvec2 &size);
    void Select();
    void Deselect();
    glm::uvec2 GetSize()
    {
        return mSize;
    }
    Texture GetTexture();

  private:
    glm::uvec2 mSize = glm::uvec2(800, 600);
    uint32_t mId = UINT32_MAX;
    static uint32_t mSelectedId;
};