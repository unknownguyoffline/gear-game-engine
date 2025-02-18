#pragma once
#include <glm/glm.hpp>
#include <stdint.h>

class Window
{
  public:
    virtual const char *getTitle() = 0;
    virtual glm::uvec2 getSize() = 0;
    virtual glm::uvec2 getPosition() = 0;
    virtual bool isOpen() = 0;
    virtual void swapBuffer() = 0;
};

Window *createWindow(const char *title, uint32_t width, uint32_t height);
void pollEvent();