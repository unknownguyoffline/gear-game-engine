#pragma once
#include <string>
#include <renderer/Types.hpp>

struct EntityMetadataComponent
{
    std::string name;
};

struct TransformComponent
{
    Transform transform;
};

struct QuadrilateralComponent
{
    glm::vec4 color = glm::vec4(1, 1, 1, 1);
};

struct CameraComponent
{
    float fov = 90.f;
    float nearPlane = 0.01f;
    float farPlane = 100.f;
    static Entity currentCamera;
};
