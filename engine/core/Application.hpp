#pragma once
#include "core/Macro.hpp"
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

    static Application *getInstance()
    {
        if (mInstance == nullptr)
        {
            CORE_ERROR("Application has not been created");
        }
        return mInstance;
    }

    void run();
    void close();

    static Application *create(int argc, char **argv);
    static Application *createApplication(int argc, char **argv);

    Application(const Application &) = delete;
    void operator=(const Application &) = delete;

    Console console;

    ~Application()
    {
    }

    Application()
    {
    }

  private:
    bool mRunning = false;
    static Application *mInstance;
};
} // namespace Gear
