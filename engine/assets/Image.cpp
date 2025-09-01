#include "Image.hpp"
#include <stb/stb_image.h>

Image::Image()
{
}
Image::Image(const char *filename)
{
    Load(filename);
}

Image::~Image()
{
    if (data != nullptr)
        free(data);
}

void Image::Load(const char *filename)
{
    assert(fopen(filename, "r") != NULL);
    int width, height, channel;
    data = stbi_load(filename, &width, &height, &channel, 0);
    size = {width, height};
    format = ImageFormat(channel - 1);
}
