#pragma once
#include "utility/Console.hpp"

namespace Gear
{
class Application
{
  public:
    virtual void start()
    {
    }
    virtual void update()
    {
    }
    virtual void end()
    {
    }

    void run();
    void close();

    static Application *create(int argc, char **argv);

    Console console;

  private:
    bool mRunning = false;
};
} // namespace Gear
