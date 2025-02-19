#include "GraphicContext.hpp"
#include "Window.hpp"
#include <GLFW/glfw3.h>

class LinuxWindow : public Window
{
  public:
    const char *getTitle() override;
    glm::uvec2 getSize() override;
    glm::uvec2 getPosition() override;
    void *getNativeWindow() override;
    GraphicContext *createGraphicContext(GraphicApi api) override;
    bool isOpen() override;
    void swapBuffer() override;
    WindowApi getWindowApi() override;
    LinuxWindow(const char *title, uint32_t width, uint32_t height);
    ~LinuxWindow();

  private:
    GLFWwindow *mWindow = nullptr;
    WindowApi mApi = GLFW;
    static uint32_t mWindowCount;
};
