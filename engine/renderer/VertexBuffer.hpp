#pragma once
#include <stdint.h>
#include <vector>
#include "renderer/Types.hpp"

enum LayoutType
{
    FLOAT,
    VEC2,
    VEC3,
    VEC4,
    INT,
    IVEC2,
    IVEC3,
    IVEC4,
};

class VertexBuffer
{

  public:
    void Select() const;
    void Deselect() const;

    size_t GetSize() const;
    size_t GetCapacity() const;
    uint32_t GetStride() const;

    void SetData(size_t size, void *data);
    void SubData(size_t size, void *data, size_t offset);

    void Create(GraphicBufferUsage usage = STATIC_DRAW);
    void Create(size_t size, void *data, GraphicBufferUsage usage = STATIC_DRAW);

    void AddLayout(LayoutType type);
    void ClearLayout();

  private:
    uint32_t mId = UINT_MAX;
    size_t mSize = UINT_MAX;
    size_t mCapacity = UINT_MAX;
    size_t mStride = 0;
    std::vector<LayoutType> mLayout;
    GraphicBufferUsage mUsage = STATIC_DRAW;

    static uint32_t mSelectedId;
};
