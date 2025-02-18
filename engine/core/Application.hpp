#pragma once
#include "core/Macro.hpp"
#include "core/Window.h"
#include <memory>
#include <string>

struct ApplicationInitInfo
{
    glm::uvec2 windowSize = glm::uvec2(800, 600);
    std::string windowTitle = "Untitled";
};

namespace Gear
{
class Application
{
  public:
    virtual void initialize()
    {
    }
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
    void applicationLoop();
    void close();

    static Application *create(int argc, char **argv);
    static Application *createApplication(int argc, char **argv);

    Application(const Application &) = delete;
    void operator=(const Application &) = delete;

    ~Application()
    {
    }

    Application()
    {
    }

    std::shared_ptr<Window> window;

    ApplicationInitInfo applicationInitInfo;

  private:
    bool mRunning = false;
    static Application *mInstance;
};
} // namespace Gear
