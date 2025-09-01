#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"
#include "Macro.hpp"
#include "input/Mouse.hpp"
#include "input/Keyboard.hpp"

#define MOUSE_BUTTON_CHECK(button, pressExpression, releaseExpression)                                                 \
    if (glfwGetMouseButton((GLFWwindow *)mNativeWindow, button) == GLFW_PRESS)                                         \
    {                                                                                                                  \
        pressExpression;                                                                                               \
    }                                                                                                                  \
    else if (glfwGetMouseButton((GLFWwindow *)mNativeWindow, button) == GLFW_RELEASE)                                  \
    {                                                                                                                  \
        releaseExpression;                                                                                             \
    }

uint32_t Window::mWindowCount = 0;

const char *Window::getTitle()
{
    return glfwGetWindowTitle((GLFWwindow *)mNativeWindow);
}

glm::uvec2 Window::getSize()
{
    int width, height;
    glfwGetWindowSize((GLFWwindow *)mNativeWindow, &width, &height);
    return glm::uvec2(width, height);
}

glm::uvec2 Window::getPosition()
{
    int x, y;
    glfwGetWindowPos((GLFWwindow *)mNativeWindow, &x, &y);
    return glm::uvec2(x, y);
}

void *Window::getNativeWindow()
{
    return (GLFWwindow *)mNativeWindow;
}

bool Window::isOpen()
{
    return !glfwWindowShouldClose((GLFWwindow *)mNativeWindow);
}
void scrollCallback(GLFWwindow *window, double xoffset, double yoffset)
{
    Mouse::scrollOffset = glm::vec2(xoffset, yoffset);
}
void Window::create(const char *title, const glm::uvec2 &size)
{
    if (mWindowCount == 0)
    {
        glfwInit();
    }
    mWindowCount++;

    mNativeWindow = glfwCreateWindow(size.x, size.y, title, nullptr, nullptr);

    if ((GLFWwindow *)mNativeWindow == nullptr)
    {
        CORE_ERROR("Failed to create window");
    }

    glfwMakeContextCurrent((GLFWwindow *)mNativeWindow);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        CORE_ERROR("Failed to initialize glad");
        glfwTerminate();
    }

    glfwSetScrollCallback((GLFWwindow *)mNativeWindow, scrollCallback);
}

void Window::swapBuffer()
{
    glfwSwapBuffers((GLFWwindow *)mNativeWindow);
}

void Window::destroy()
{
    glfwDestroyWindow((GLFWwindow *)mNativeWindow);
    mWindowCount--;
    if (mWindowCount == 0)
        glfwTerminate();
}

void pollEvent()
{
    Mouse::scrollOffset = glm::vec2(0);
    glfwPollEvents();
}
void Window::processInput()
{
    if (Mouse::hideCursor)
        glfwSetInputMode((GLFWwindow *)mNativeWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    else
        glfwSetInputMode((GLFWwindow *)mNativeWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glm::dvec2 position;
    glfwGetCursorPos((GLFWwindow *)mNativeWindow, &position.x, &position.y);
    Mouse::offset = glm::vec2(position) - Mouse::position;
    Mouse::position = position;
    MOUSE_BUTTON_CHECK(GLFW_MOUSE_BUTTON_LEFT, Mouse::leftPress = true, Mouse::leftPress = false);
    MOUSE_BUTTON_CHECK(GLFW_MOUSE_BUTTON_MIDDLE, Mouse::middlePress = true, Mouse::middlePress = false);
    MOUSE_BUTTON_CHECK(GLFW_MOUSE_BUTTON_RIGHT, Mouse::rightPress = true, Mouse::rightPress = false);
    if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_W) == GLFW_PRESS)
    {
        Keyboard::w = true;
    }
    else if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_W) == GLFW_RELEASE)
    {
        Keyboard::w = false;
    }
    if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_S) == GLFW_PRESS)
    {
        Keyboard::s = true;
    }
    else if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_S) == GLFW_RELEASE)
    {
        Keyboard::s = false;
    }
    if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_D) == GLFW_PRESS)
    {
        Keyboard::d = true;
    }
    else if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_D) == GLFW_RELEASE)
    {
        Keyboard::d = false;
    }
    if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_A) == GLFW_PRESS)
    {
        Keyboard::a = true;
    }
    else if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_A) == GLFW_RELEASE)
    {
        Keyboard::a = false;
    }
    if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        Keyboard::space = true;
    }
    else if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_SPACE) == GLFW_RELEASE)
    {
        Keyboard::space = false;
    }
    if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        Keyboard::leftShift = true;
    }
    else if (glfwGetKey((GLFWwindow *)mNativeWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
    {
        Keyboard::leftShift = false;
    }
}
float Window::getAspectRatio()
{
    int width, height;
    glfwGetWindowSize((GLFWwindow *)mNativeWindow, &width, &height);
    return float(width) / float(height);
}
