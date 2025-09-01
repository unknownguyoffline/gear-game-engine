#pragma once
#include <stdint.h>
#include <stddef.h>
#include "renderer/Types.hpp"

class IndexBuffer
{
  public:
    void Select() const;
    void Deselect() const;

    size_t SetSize() const;
    size_t GetCapacity() const;

    void SetData(size_t size, void *data);
    void SubData(size_t size, void *data, size_t offset);

    void Create(GraphicBufferUsage usage = STATIC_DRAW);
    void Create(size_t size, void *data, GraphicBufferUsage usage = STATIC_DRAW);

  private:
    uint32_t mId = UINT_MAX;
    size_t mSize = UINT_MAX;
    size_t mCapacity = UINT_MAX;
    GraphicBufferUsage mUsage = STATIC_DRAW;
    static uint32_t mSeletedId;
};
