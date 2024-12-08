#include <Engine.hpp>

class App : public New::Application
{
  public:
    void start() override
    {
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
    }

    void update() override
    {
    }
    void end() override
    {
    }

  private:
};

New::Application *New::Application::create(int argc, char **argv)
{
    return new App;
}
