#include <glad/glad.h>
#include "LinuxWindow.hpp"
#include "platform/opengl/OpenglGraphicContext.hpp"
#include <Macro.hpp>

uint32_t LinuxWindow::mWindowCount = 0;

Window *createWindow(const char *title, uint32_t width, uint32_t height)
{
    return new LinuxWindow(title, width, height);
}

GraphicContext *LinuxWindow::createGraphicContext(GraphicApi api)
{
    if (api == OPENGL)
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            CORE_ERROR("Glad failed to create OPENGL CONTEXT");
        }
        return new OpenglGraphicContext;
    }
    else if (api == OPENGL)
    {
        CORE_ERROR("Not support for [VULKAN]");
    }
    else if (api == DIRECTX)
    {
        CORE_ERROR("Linux doesn't support [DIRECTX]");
    }
    return nullptr;
}

WindowApi LinuxWindow::getWindowApi()
{
    return mApi;
}
const char *LinuxWindow::getTitle()
{
    return glfwGetWindowTitle(mWindow);
}

glm::uvec2 LinuxWindow::getSize()
{
    int width, height;
    glfwGetWindowSize(mWindow, &width, &height);
    return glm::uvec2(width, height);
}

glm::uvec2 LinuxWindow::getPosition()
{
    int x, y;
    glfwGetWindowPos(mWindow, &x, &y);
    return glm::uvec2(x, y);
}

void *LinuxWindow::getNativeWindow()
{
    return mWindow;
}

bool LinuxWindow::isOpen()
{
    return !glfwWindowShouldClose(mWindow);
}

LinuxWindow::LinuxWindow(const char *title, uint32_t width, uint32_t height)
{
    if (mWindowCount == 0)
    {
        glfwInit();
    }
    mWindowCount++;

    mWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (mWindow == nullptr)
    {
        CORE_ERROR("Failed to create window");
    }

    glfwMakeContextCurrent(mWindow);
}

void LinuxWindow::swapBuffer()
{
    glfwSwapBuffers(mWindow);
}

LinuxWindow::~LinuxWindow()
{
    glfwDestroyWindow(mWindow);
    mWindowCount--;
    if (mWindowCount == 0)
        glfwTerminate();
}

void pollEvent()
{
    glfwPollEvents();
}
