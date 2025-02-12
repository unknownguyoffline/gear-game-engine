#include "core/MemoryManager.hpp"
#include <Engine.hpp>
#include <core/Macro.hpp>

class App : public Gear::Application
{
  public:
    void start() override
    {
        testConsoleLogErrorChecker();
        testConsoleLog();
        testConsoleLogWithEnding();
        testLoggingCoreMacro();
        testLoggingClientMacro();
        testMemoryManager();
    }

    void update() override
    {
    }
    void end() override
    {
    }
    void testConsoleLogErrorChecker()
    {
        printf("[TESTING CONSOLE LOGGING ERROR CHECKER]\n");
        console.log("testing {float", 10.5);
        console.log("testing {float {int}", 10.5);
        console.log("testing {float  {}", 10.5);
        console.log("testing {float  }", 10.5);
    }
    void testConsoleLog()
    {
        printf("[TESTING CONSOLE LOGGING]\n");
        console.log("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.warn("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.error("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.fatal("testing {float} {int} {string}", 10.5, 20, "end of line");
    }
    void testConsoleLogWithEnding()
    {
        printf("[TESTING CONSOLE WITH DIFFERENT END]\n");
        console.end = "end testing\n";
        console.log("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.warn("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.error("testing {float} {int} {string}", 10.5, 20, "end of line");
        console.fatal("testing {float} {int} {string}", 10.5, 20, "end of line");
    }
    void testLoggingCoreMacro()
    {
        printf("[TESTING CORE LOGGING MACROS]\n");
        CORE_LOG("testing {float} {int} {string}", 10.5, 20, "end of line");
        CORE_WARN("testing {float} {int} {string}", 10.5, 20, "end of line");
        CORE_ERROR("testing {float} {int} {string}", 10.5, 20, "end of line");
        CORE_FATAL("testing {float} {int} {string}", 10.5, 20, "end of line");
    }
    void testLoggingClientMacro()
    {
        printf("[TESTING CLIENT LOGGING MACROS]\n");
        CLIENT_LOG("testing {float} {int} {string}", 10.5, 20, "end of line");
        CLIENT_WARN("testing {float} {int} {string}", 10.5, 20, "end of line");
        CLIENT_ERROR("testing {float} {int} {string}", 10.5, 20, "end of line");
        CLIENT_FATAL("testing {float} {int} {string}", 10.5, 20, "end of line");
    }
    void testMemoryManager()
    {
        CLIENT_LOG("[TESTING MEMORY MANAGER]");
        MemoryManager memoryManager;
        CLIENT_LOG("int pointer1: {pointer}", new int);
        CLIENT_LOG("2 char pointer2: {pointer}", new char[2]);
        CLIENT_LOG("char pointer3: {pointer}", new char);
        CLIENT_LOG("char pointer3: {pointer}", new char);
        CLIENT_LOG("char pointer4: {pointer}", new char);
    }

  private:
};

Gear::Application *Gear::Application::create(int argc, char **argv)
{
    return new App;
}
