#include <Engine.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/Macro.hpp>
#include <glm/glm.hpp>

class App : public Gear::Application
{
  public:
    void start() override
    {
        glm::vec2 color;
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            CLIENT_ERROR("Failed to initial glad");
        }
    }

    void update() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.f, 1.f, 1.f, 1.f);
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
