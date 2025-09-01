#include "Application.hpp"
#include "input/Mouse.hpp"
#include "renderer/Renderer.hpp"

Application *Application::mInstance = nullptr;

Application *Application::CreateApplication(int argc, char **argv)
{
    if (mInstance == nullptr)
        mInstance = Create(argc, argv);

    return mInstance;
}

Window &Application::GetWindow()
{
    return mWindow;
}

ApplicationInitInfo &Application::GetApplicationInitInfo()
{
    return mApplicationInitInfo;
}

Application *Application::GetInstance()
{
    if (mInstance == nullptr)
    {
        CORE_ERROR("Application has not been created");
    }
    return mInstance;
}

void Application::Run()
{
    OnInitialize();
    mWindow.Create(mApplicationInitInfo.windowTitle.c_str(), mApplicationInitInfo.windowSize);
    Renderer::Initialize();
    OnStart();
    ApplicationLoop();
    OnEnd();
    mWindow.Destroy();
}
void Application::ApplicationLoop()
{
    while (mRunning)
    {
        mRunning = mWindow.IsOpen();
        Graphic::SetViewport(mWindow.GetSize());
        PollEvent();
        mWindow.ProcessInput();
        OnUpdate();
        mWindow.SwapBuffer();
    }
}
void Application::Close()
{
    mRunning = false;
}

void Application::InitGraphic()
{
}
