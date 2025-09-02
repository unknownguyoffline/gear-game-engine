#include <Engine.hpp>
#include <entt/entt.hpp>
#include <ecs/scene.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <renderer/Color.hpp>
#include <ecs/Component.hpp>
#include <misc/cpp/imgui_stdlib.h>
#include <renderer/FrameBuffer.hpp>
#include <GLFW/glfw3.h>
#include <renderer/Shader.hpp>

class PopupWindow
{
};


const char *vertexShaderCode = R"(
#version 450
layout(location = 0)in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos, 1.0);
}
)";

const char *fragmentShaderCode = R"(
#version 450
out vec4 outputColor;
uniform vec4 color;
void main()
{
    outputColor = color;
}
)";

struct UiVariables
{
    std::string entityName;
    bool mEntitySelected = false;
    Entity mSelectedEntity;
    bool openShowWindow = false;
    glm::uvec2 gameWindowSize = {0, 0};
};

class EditorUi
{
  public:
    Mesh mesh;
    Shader shader;
    void Initialize(GLFWwindow* window)
    {
        mesh.vertices.push_back({glm::vec3(0.5, 0.5, 0.0), glm::vec2(0, 0), glm::vec3(0, 0, 0)});
        mesh.vertices.push_back({glm::vec3(0.5,-0.5, 0.0), glm::vec2(0, 0), glm::vec3(0, 0, 0)});
        mesh.vertices.push_back({glm::vec3(-0.5,-0.5, 0.0), glm::vec2(0, 0), glm::vec3(0, 0, 0)});
        mesh.vertices.push_back({glm::vec3(-0.5, 0.5, 0.0), glm::vec2(0, 0), glm::vec3(0, 0, 0)});

        mesh.indices = {0, 1, 2, 2, 3, 0};

        mesh.CreateBuffers();

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init();
        
        ImGui::GetIO().Fonts->AddFontFromFileTTF("pt-root-ui_regular.ttf");
        ImGui::GetIO().FontGlobalScale = 1.2f;

        ImGui::GetStyle().WindowPadding = ImVec2(2, 2);

        // framebuffer creation


        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        mFrameBuffer.Create({uint32_t(width), uint32_t(height)});
        mFrameBufferTexture = mFrameBuffer.GetTexture();
        

        shader.Create(vertexShaderCode, fragmentShaderCode);
    }

    void Update()
    {

        // render game

        //auto cameraView = mScene->GetRegistry().view<CameraComponent>();
        //for (entt::entity e : cameraView)
        //{

        //}


        mFrameBuffer.Select();
        Graphic::SetViewport(mUiVariables.gameWindowSize);
        Renderer::ClearScreen(glm::vec4(0.5333,0.5333,0.5333,1));

        auto quadrilateralView = mScene->GetRegistry().view<QuadrilateralComponent>();
        for (entt::entity e : quadrilateralView)
        {
            Entity entity = mScene->GetEntityFromEntt(e);
            QuadrilateralComponent component = entity.GetComponent<QuadrilateralComponent>();
            shader.Select();
            shader.SetUniformVec4(component.color, "color");
            Renderer::Submit(mesh);
        }


        mFrameBuffer.Deselect();

        // render imgui ui

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());


        if (mScene != nullptr)
        {
            if (mUiVariables.openShowWindow)
                ImGui::ShowDemoWindow(&mUiVariables.openShowWindow);
            SceneHierarchyPanel();
        }
        GameWindow();
        EntityPropertyPanel();


        ImGui::Render();

        Renderer::ClearScreen(Color::White); 
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Terminate()
    {
    }

    void SetScene(Scene& scene)
    {
        mScene = &scene;
    }

    void SceneHierarchyPanel()
    {
        
        ImGui::Begin("Scene hierarchy");
        ImGui::Checkbox("show demo window", &mUiVariables.openShowWindow);
        if (ImGui::Button("Add Entity", ImVec2(ImGui::GetWindowSize().x, 0)))
            ImGui::OpenPopup("Create Entity");

        if (ImGui::BeginPopup("Create Entity"))
        {
            ImGui::InputText("Name", &mUiVariables.entityName);
            if (ImGui::Button("Create") && mUiVariables.entityName[0] != 0)
            {
                mScene->CreateEntity(mUiVariables.entityName.c_str());
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel"))
                ImGui::CloseCurrentPopup();

            ImGui::EndPopup();
        }

        auto view = mScene->GetRegistry().view<EntityMetadataComponent>();
        for (entt::entity e : view)
        {
            Entity entity = mScene->GetEntityFromEntt(e);
            EntityMetadataComponent &metadata = entity.GetComponent<EntityMetadataComponent>();
            if (ImGui::Button(metadata.name.c_str(), ImVec2(ImGui::GetWindowSize().x, 0)))
            {
                mUiVariables.mSelectedEntity = entity;
                mUiVariables.mEntitySelected = true;
            }
        }
        ImGui::End();
    }
    void GameWindow()
    {
        ImGui::Begin("Game window");

        ImGui::Image(mFrameBufferTexture.GetId(), {ImGui::GetWindowSize().x, ImGui::GetWindowSize().y - 35});
        if (ImGui::GetWindowSize().x != mUiVariables.gameWindowSize.x ||
            ImGui::GetWindowSize().y - 35 != mUiVariables.gameWindowSize.y)
        {
            mUiVariables.gameWindowSize = {ImGui::GetWindowSize().x, ImGui::GetWindowSize().y - 35};
            mFrameBuffer.Create(mUiVariables.gameWindowSize);
            mFrameBufferTexture = mFrameBuffer.GetTexture();
        }

        ImGui::End();
    }
    void EntityPropertyPanel()
    {

        ImGui::Begin("Entity properties");
        if (mUiVariables.mEntitySelected == false)
        {
            ImGui::End();
            return;
        }

        if (ImGui::Button("Add Component"))
        {
            ImGui::OpenPopup("Add Component");
        }
        if (ImGui::BeginPopup("Add Component"))
        {
            ImVec2 buttonSize = ImVec2(250, 0);
            if (ImGui::Button("Cancel"))
            {
                ImGui::CloseCurrentPopup();
            }
            if (ImGui::Button("Quadrilateral Component", buttonSize))
                mUiVariables.mSelectedEntity.AddComponent<QuadrilateralComponent>();
            if (ImGui::Button("Camera Component", buttonSize))
                mUiVariables.mSelectedEntity.AddComponent<CameraComponent>();
            ImGui::EndPopup();
        }

        if (mUiVariables.mEntitySelected)
        {
            if (mUiVariables.mSelectedEntity.HasComponent<EntityMetadataComponent>())
            {
                EntityMetadataComponent &metadata = mUiVariables.mSelectedEntity.GetComponent<EntityMetadataComponent>();
                ImGui::PushID("EntityMetadataComponent");
                ImGui::SeparatorText("Entity metadata");
                ImGui::InputText("Name", &metadata.name);
                ImGui::PopID();
                if (metadata.name[0] == 0)
                {
                    metadata.name = "Untitled";
                }

            }

            if (mUiVariables.mSelectedEntity.HasComponent<TransformComponent>())
            {
                Transform &transform = mUiVariables.mSelectedEntity.GetComponent<TransformComponent>().transform;
                ImGui::PushID("TransformComponent");
                ImGui::SeparatorText("Transform Component");
                ImGui::DragFloat3("Position", &transform.position.x);
                ImGui::DragFloat3("Rotation", &transform.rotation.x);
                ImGui::DragFloat3("Scale", &transform.scale.x);
                ImGui::PopID();
            }
            if (mUiVariables.mSelectedEntity.HasComponent<QuadrilateralComponent>())
            {
                ImGui::PushID("QuadrilateralComponent");
                ImGui::SeparatorText("Quadrilateral Component");
                ImGui::ColorEdit4("color", &mUiVariables.mSelectedEntity.GetComponent<QuadrilateralComponent>().color.r);
                ImGui::PopID();
            }
            if (mUiVariables.mSelectedEntity.HasComponent<CameraComponent>())
            {
                ImGui::PushID("CameraComponent");
                ImGui::SeparatorText("Camera Component");
                CameraComponent& component = mUiVariables.mSelectedEntity.GetComponent<CameraComponent>();
                ImGui::DragFloat("Fov", &component.fov);
                ImGui::DragFloat("Near plane", &component.nearPlane);
                ImGui::DragFloat("Far plane", &component.farPlane);
                if (ImGui::Button("Set as current camera"))
                {
                    CameraComponent::currentCamera = mUiVariables.mSelectedEntity;
                }
                ImGui::PopID();
            }
        }
        ImGui::End();
    }

  private:
    UiVariables mUiVariables;
    Scene *mScene = nullptr;
    FrameBuffer mFrameBuffer;
    Texture mFrameBufferTexture;


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