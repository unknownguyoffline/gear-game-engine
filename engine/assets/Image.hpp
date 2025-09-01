#pragma once
#include <glm/glm.hpp>
#include "renderer/Types.hpp"

struct Image
{
    void Load(const char *filename);
    Image(const char *filename);
    Image();
    ~Image();


    unsigned char *data = nullptr;
    glm::uvec2 size = glm::uvec2(0);
    ImageFormat format;
};
