#pragma once
#include "GraphicContext.hpp"
#include "Window.hpp"

class OpenglGraphicContext : public GraphicContext
{
  public:
    void init() override;
};
