#include "Window.hpp"
#include <GLFW/glfw3.h>

class WindowsWindow : public Window
{
  public:
    const char *getTitle() override;
    glm::uvec2 getSize() override;
    glm::uvec2 getPosition() override;
    bool isOpen() override;
    void swapBuffer() override;
    WindowsWindow(const char *title, uint32_t width, uint32_t height);
    ~WindowsWindow();

  private:
    GLFWwindow *mWindow = nullptr;
    static uint32_t mWindowCount;
};
