#include "EntryPoint.hpp"
#include "Application.hpp"

int main(int argc, char **argv)
{
    Gear::Application *application = Gear::Application::createApplication(argc, argv);
    application->run();
    delete application;
    return 0;
}
