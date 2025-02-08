#include <Engine.hpp>
#include <core/Macro.hpp>

class App : public Gear::Application
{
  public:
    void start() override
    {
        printf("[TESTING CONSOLE LOGGING ERROR CHECKER]\n");
        console.log("testing {float", 10.5);
        console.log("testing {float {int}", 10.5);
        console.log("testing {float  {}", 10.5);
        console.log("testing {float  }", 10.5);

        printf("[TESTING CONSOLE LOGGING]\n");
        console.log("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.warn("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.error("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.fatal("testing {float} {int} {string}", 10.5, 20, "end of line");

        printf("[TESTING CONSOLE WITH DIFFERENT END]\n");
        console.end = "end testing\n";
        console.log("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.warn("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.error("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.fatal("testing {float} {int} {string}", 10.5, 20, "end of line");

        printf("[TESTING CORE LOGGING MACROS]\n");
        CORE_LOG("testing {float} {int} {string}", 10.5, 20, "end of line");
        CORE_WARN("testing {float} {int} {string}", 10.5, 20, "end of line");
        CORE_ERROR("testing {float} {int} {string}", 10.5, 20, "end of line");
        CORE_FATAL("testing {float} {int} {string}", 10.5, 20, "end of line");

        printf("[TESTING CLIENT LOGGING MACROS]\n");
        CLIENT_LOG("testing {float} {int} {string}", 10.5, 20, "end of line");
        CLIENT_WARN("testing {float} {int} {string}", 10.5, 20, "end of line");
        CLIENT_ERROR("testing {float} {int} {string}", 10.5, 20, "end of line");
        CLIENT_FATAL("testing {float} {int} {string}", 10.5, 20, "end of line");
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
