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
    initialize();
    window.reset(createWindow(applicationInitInfo.windowTitle.c_str(), applicationInitInfo.windowSize.x,
                              applicationInitInfo.windowSize.y));
    start();
    applicationLoop();
    end();
}
void Application::applicationLoop()
{
    while (window->isOpen())
    {
        update();
        pollEvent();
        window->swapBuffer();
    }
}
void Application::close()
{
}

} // namespace Gear
