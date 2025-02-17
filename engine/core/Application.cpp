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
    start();
    end();
}
void Application::close()
{
}

} // namespace Gear
