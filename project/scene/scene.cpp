#include <Engine.hpp>
#include <entt/entt.hpp>
#include <ecs/scene.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <renderer/Color.hpp>
#include <ecs/component.hpp>

class EditorUi
{
  public:
    void Initialize(GLFWwindow *window)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init();

        ImGui::GetStyle().WindowPadding = ImVec2(0, 0);
    }

    void Update()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());
        if (mScene != nullptr)
        {
            ImGui::ShowDemoWindow();
            SceneView();
        }
        GameWindow();
        ImGui::Render();
        Renderer::ClearScreen(Color::White);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Terminate()
    {
    }

    void SetScene(Scene &scene)
    {
        mScene = &scene;
    }

    void SceneView()
    {
        static int toggleCreateEntityWindow = false;
        static char entityName[512];
        ImGui::Begin("Scene hierarchy");
        if (ImGui::Button("Add Entity", ImVec2(ImGui::GetWindowSize().x, 0)))
            toggleCreateEntityWindow = toggleCreateEntityWindow ? false : true;

        if (toggleCreateEntityWindow)
        {
            ImGui::Begin("Create Entity");
            ImGui::InputText("Name", entityName, 512);
            if (ImGui::Button("Create") && entityName[0] != 0)
            {
                mScene->CreateEntity(entityName);
                toggleCreateEntityWindow = toggleCreateEntityWindow ? false : true;

            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel"))
                toggleCreateEntityWindow = toggleCreateEntityWindow ? false : true;


            ImGui::End();
        }


        auto view = mScene->GetRegistry().view<EntityMetadataComponent>();
        for (entt::entity e : view)
        {
            Entity entity = mScene->GetEntityFromEntt(e);
            EntityMetadataComponent &metadata = entity.GetComponent<EntityMetadataComponent>();
            if (ImGui::Button(metadata.name.c_str()))
            {
            }
        }
        ImGui::End();
    }
    void GameWindow()
    {
        ImGui::Begin("Game window");
        ImGui::End();
    }

  private:
    Scene *mScene = nullptr;

};

class SceneDevelopment : public Application
{
    Scene mainScene;
    EditorUi editorUi;
    void OnStart() override
    {
        editorUi.Initialize((GLFWwindow *)GetWindow().GetNativeWindow());
        editorUi.SetScene(mainScene);
    }
    void OnUpdate() override
    {
        editorUi.Update();
    }
    void OnEnd() override
    {
        editorUi.Terminate();
    }
};

CREATE_APPLICATION(SceneDevelopment)