#include "Application.hpp"

namespace Gear
{

Application *Application::mInstance = nullptr;

Application *Application::createApplication(int argc, char **argv)
{
    if (mInstance == nullptr)
        mInstance = create(argc, argv);

    return mInstance;
}

void Application::run()
{
    init();
    mWindow.reset(createWindow(mApplicationInitInfo.windowTitle.c_str(), mApplicationInitInfo.windowSize.x,
                               mApplicationInitInfo.windowSize.y));
    initGraphic();
    start();
    applicationLoop();
    end();
}
void Application::initGraphic()
{
    mGraphicContext.reset(mWindow->createGraphicContext(mApplicationInitInfo.graphicApi));
    mGraphicContext->init();
}
void Application::applicationLoop()
{
    while (mRunning)
    {
        mRunning = mWindow->isOpen();
        update();
        pollEvent();
        mWindow->swapBuffer();
    }
}
void Application::close()
{
}

} // namespace Gear
