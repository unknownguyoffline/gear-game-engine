#pragma once
#include <glm/glm.hpp>
#include <stdint.h>

class Window
{
  public:
    const char *GetTitle();
    glm::uvec2 GetSize();
    glm::uvec2 GetPosition();
    void *GetNativeWindow();
    float GetAspectRatio();
    bool IsOpen();
    void SwapBuffer();
    void ProcessInput();
    void Create(const char *title, const glm::uvec2 &size);
    void Destroy();

  private:
    void *mNativeWindow = nullptr;
    static uint32_t mWindowCount;
};

void PollEvent();
