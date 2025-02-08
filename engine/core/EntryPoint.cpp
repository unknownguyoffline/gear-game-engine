#include "EntryPoint.hpp"
#include "Application.hpp"

int main(int argc, char **argv)
{
    Gear::Application *application = Gear::Application::create(argc, argv);
    application->run();
    delete application;
}
