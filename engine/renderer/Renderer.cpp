#include "renderer/Renderer.hpp"
#include "core/Macro.hpp"
#include "Graphic.hpp"

using namespace Graphic;

void Renderer::Initialize()
{
    EnableDepthTest(true);
    EnableBlending(true);
    EnableBackFaceCulling(false);
}
void Renderer::Submit(const VertexBuffer &vbo, const IndexBuffer &ibo, int indexCount)
{
    vbo.Select();
    ibo.Select();
    DrawElements(indexCount, TRIANGLE);
}

void Renderer::Submit(const VertexBuffer &vbo, int vertexCount)
{
    vbo.Select();
    DrawArrays(vertexCount, TRIANGLE);
}

void Renderer::Submit(const Mesh &mesh)
{
    mesh.SelectBuffers();
    DrawElements(mesh.indices.size());
}

void Renderer::ClearScreen(const glm::vec4 &color)
{
    SetClearColor(color);
    ClearColorBuffer();
    ClearDepthBuffer();
}
