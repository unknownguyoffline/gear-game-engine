#pragma once
#include "core/Macro.hpp"
#include "core/Window.hpp"
#include <memory>
#include <string>
#include "renderer/Graphic.hpp"
#include "renderer/Renderer.hpp"
#include "input/Mouse.hpp"
#include "input/Keyboard.hpp"

struct ApplicationInitInfo
{
    glm::uvec2 windowSize = glm::uvec2(800, 600);
    std::string windowTitle = "Untitled";
};

class Application
{
  public:
    virtual void OnInitialize()
    {
    }
    virtual void OnStart()
    {
    }
    virtual void OnUpdate()
    {
    }
    virtual void OnEnd()
    {
    }


    void Run();
    void ApplicationLoop();
    void Close();
    void InitGraphic();

    static Application *GetInstance();
    static Application *Create(int argc, char **argv);
    static Application *CreateApplication(int argc, char **argv);

    Application(const Application &) = delete;
    void operator=(const Application &) = delete;
    Window &GetWindow();
    ~Application()
    {
    }

    Application()
    {
    }

    ApplicationInitInfo &GetApplicationInitInfo();

  private:
    bool mRunning = true;
    static Application *mInstance;
    Window mWindow;
    ApplicationInitInfo mApplicationInitInfo;
};
