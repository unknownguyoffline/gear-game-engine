#include "EntryPoint.hpp"
#include "Application.hpp"

int main(int argc, char **argv)
{
    New::Application *application = New::Application::create(argc, argv);
    application->run();
    delete application;
}
