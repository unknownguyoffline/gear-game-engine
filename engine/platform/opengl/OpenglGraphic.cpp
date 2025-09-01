#include "renderer/Graphic.hpp"
#include <cassert>
#include <glad/glad.h>

GLenum glDrawMode[] = {GL_TRIANGLES, GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP, GL_LINES, GL_POINTS};
namespace Graphic
{
void ClearDepthBuffer()
{
    glClear(GL_DEPTH_BUFFER_BIT);
}

void SetClearColor(const glm::vec4 &color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

void ClearColorBuffer()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void SetViewport(const glm::ivec2 &size, const glm::ivec2 &position)
{
    glViewport(position.x, position.y, size.x, size.y);
}

void DrawArrays(uint32_t count, DrawMode mode)
{
    glPointSize(10.f);
    glDrawArrays(glDrawMode[mode], 0, count);
}

void DrawElements(uint32_t count, DrawMode mode)
{
    glDrawElements(glDrawMode[mode], count, GL_UNSIGNED_INT, 0);
}

void EnableDepthTest(bool enable)
{
    enable ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
}
void EnableBackFaceCulling(bool enable)
{
    enable ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);
}
void EnableBlending(bool enable)
{
    if (enable)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    else
    {
        glDisable(GL_BLEND);
    }
}
void enableWireframe(bool enable)
{
    enable ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
} // namespace Graphic
