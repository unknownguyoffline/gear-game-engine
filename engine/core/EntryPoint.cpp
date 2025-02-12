#include "EntryPoint.hpp"
#include "Application.hpp"
#include "core/MemoryManager.hpp"

void *operator new(size_t size)
{
    void *ptr = MemoryManager::getMemory<char>(size);
    CORE_LOG("Memory Allocate: {int} {pointer}", size, ptr);
    return ptr;
}
void operator delete(void *ptr) noexcept
{
    CORE_LOG("Memory Deallocate: {pointer}", ptr);
}
void operator delete[](void *ptr) noexcept
{
    CORE_LOG("Memory Deallocate: {pointer}", ptr);
}

int main(int argc, char **argv)
{
    Gear::Application *application = Gear::Application::createApplication(argc, argv);
    application->run();
    delete application;
    return 0;
}
