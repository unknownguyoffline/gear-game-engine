#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "renderer/VertexBuffer.hpp"
#include "renderer/IndexBuffer.hpp"
#include "renderer/Types.hpp"

class Mesh
{
  public:
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;

    VertexBuffer vertexBuffer;
    IndexBuffer indexBuffer;

    void CreateBuffers();
    void SelectBuffers() const;
};
