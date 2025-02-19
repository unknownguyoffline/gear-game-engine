#pragma once
#include "core/Macro.hpp"
#include "core/Window.hpp"
#include <memory>
#include <string>

struct ApplicationInitInfo
{
    glm::uvec2 windowSize = glm::uvec2(800, 600);
    std::string windowTitle = "Untitled";
    GraphicApi graphicApi = OPENGL;
};

namespace Gear
{
class Application
{
  public:
    virtual void init()
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
    void initGraphic();

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

    ApplicationInitInfo &getApplicationInitInfo()
    {
        return mApplicationInitInfo;
    }

  private:
    bool mRunning = true;
    static Application *mInstance;
    std::shared_ptr<GraphicContext> mGraphicContext;
    std::shared_ptr<Window> mWindow;
    ApplicationInitInfo mApplicationInitInfo;
};
} // namespace Gear
