#pragma once
#include "renderer/VertexBuffer.hpp"
#include "renderer/IndexBuffer.hpp"
#include "renderer/Mesh.hpp"

class Renderer
{
  public:
    static void Initialize();
    static void Submit(const VertexBuffer &vbo, const IndexBuffer &ibo, int indexCount);
    static void Submit(const VertexBuffer &vbo, int vertexCount);
    static void Submit(const Mesh &mesh);
    static void ClearScreen(const glm::vec4 &color = glm::vec4(1, 0, 1, 1));
};
