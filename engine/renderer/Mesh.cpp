#include "Mesh.hpp"

void Mesh::CreateBuffers()
{
    indexBuffer.Create(sizeof(uint32_t) * indices.size(), indices.data(), STATIC_DRAW);
    vertexBuffer.Create(sizeof(Vertex) * vertices.size(), vertices.data(), STATIC_DRAW);
    vertexBuffer.AddLayout(VEC3);
    vertexBuffer.AddLayout(VEC2);
    vertexBuffer.AddLayout(VEC3);
}

void Mesh::SelectBuffers() const
{
    vertexBuffer.Select();
    indexBuffer.Select();
}
