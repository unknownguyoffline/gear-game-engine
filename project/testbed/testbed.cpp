#include <Engine.hpp>
#include <core/Macro.hpp>

class App : public Gear::Application
{
  public:
    void start() override
    {
    }

    void update() override
    {
    }
    void end() override
    {
    }

  private:
};

Gear::Application *Gear::Application::create(int argc, char **argv)
{
    return new App;
}
