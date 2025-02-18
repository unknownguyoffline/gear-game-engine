#include "WindowsWindow.h"
#include <Macro.hpp>

uint32_t WindowsWindow::mWindowCount = 0;

Window *createWindow(const char *title, uint32_t width, uint32_t height)
{
    return new WindowsWindow(title, width, height);
}

const char *WindowsWindow::getTitle()
{
    return glfwGetWindowTitle(mWindow);
}

glm::uvec2 WindowsWindow::getSize()
{
    int width, height;
    glfwGetWindowSize(mWindow, &width, &height);
    return glm::uvec2(width, height);
}

glm::uvec2 WindowsWindow::getPosition()
{
    int x, y;
    glfwGetWindowPos(mWindow, &x, &y);
    return glm::uvec2(x, y);
}

bool WindowsWindow::isOpen()
{
    return !glfwWindowShouldClose(mWindow);
}

WindowsWindow::WindowsWindow(const char *title, uint32_t width, uint32_t height)
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

void WindowsWindow::swapBuffer()
{
    glfwSwapBuffers(mWindow);
}

WindowsWindow::~WindowsWindow()
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