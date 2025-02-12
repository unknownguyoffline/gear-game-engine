#include "Application.hpp"
#include "core/MemoryManager.hpp"

namespace Gear
{

Application *Application::mInstance = nullptr;

Application *Application::createApplication(int argc, char **argv)
{
    MemoryManager::allocate(1024);
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
