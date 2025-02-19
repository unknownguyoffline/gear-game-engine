#pragma once
#include <glm/glm.hpp>
#include <stdint.h>
#include <core/GraphicContext.hpp>

enum WindowApi
{
    WINDOW,
    X11,
    WAYLAND,
    GLFW
};

enum GraphicApi
{
    OPENGL,
    VULKAN,
    DIRECTX
};

class Window
{
  public:
    virtual const char *getTitle() = 0;
    virtual glm::uvec2 getSize() = 0;
    virtual glm::uvec2 getPosition() = 0;
    virtual void *getNativeWindow() = 0;
    virtual GraphicContext *createGraphicContext(GraphicApi api) = 0;
    virtual WindowApi getWindowApi() = 0;
    virtual bool isOpen() = 0;
    virtual void swapBuffer() = 0;
};

Window *createWindow(const char *title, uint32_t width, uint32_t height);
void pollEvent();
