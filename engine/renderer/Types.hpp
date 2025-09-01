#pragma once
#include <glm/glm.hpp>

enum GraphicApi
{
    OPENGL,
    VULKAN,
    DIRECTX
};

enum GraphicBufferUsage
{
    STATIC_DRAW,
    DYNAMIC_DRAW
};

enum ImageFormat
{
    R,
    RG,
    RGB,
    RGBA
};

struct Vertex
{
    glm::vec3 position = glm::vec3(0.0);
    glm::vec2 uv = glm::vec2(0.0);
    glm::vec3 normal = glm::vec3(0.0);
};

struct Transform
{
    glm::vec3 position = glm::vec3(0);
    glm::vec3 rotation = glm::vec3(0);
    glm::vec3 scale = glm::vec3(1);
};

glm::mat4 getModelMatrix(const Transform &transform);