#pragma once
#include "renderer/Texture.hpp"
#include "renderer/Shader.hpp"

struct Material
{
    Texture diffuse;
    Texture specular;
    Texture normal;
    Texture emission;
    Texture metallic;
    Texture roughness;
    Shader shader;
};
