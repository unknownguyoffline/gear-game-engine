#pragma once
#include <stdint.h>

class Window
{
  public:
};

Window *createWindow(const char *title, uint32_t width, uint32_t height);