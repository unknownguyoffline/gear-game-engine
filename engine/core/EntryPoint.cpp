#include "EntryPoint.hpp"
#include "Application.hpp"

int main(int argc, char **argv)
{
    Application *application = Application::CreateApplication(argc, argv);
    application->Run();
    delete application;
    return 0;
}
