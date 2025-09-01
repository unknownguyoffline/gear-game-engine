#pragma once
#include <glm/glm.hpp>

enum DrawMode
{
    TRIANGLE,
    TRIANGLE_FAN,
    TRIANGLE_STRIP,
    LINE,
    POINT
};

namespace Graphic
{
void EnableBlending(bool enable);
void EnableBackFaceCulling(bool enable);
void ClearColorBuffer();
void ClearDepthBuffer();
void SetClearColor(const glm::vec4 &color);
void SetViewport(const glm::ivec2 &size, const glm::ivec2 &position = glm::ivec2(0, 0));
void DrawArrays(uint32_t count, DrawMode mode = TRIANGLE);
void DrawElements(uint32_t count, DrawMode mode = TRIANGLE);
void EnableDepthTest(bool enable);
void EnableWireframe(bool enable);
} // namespace Graphic
