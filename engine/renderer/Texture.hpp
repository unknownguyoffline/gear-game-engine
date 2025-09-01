#pragma once
#include <glm/glm.hpp>
#include "renderer/Types.hpp"
#include "assets/Image.hpp"

enum TextureFilter
{
    NEAREST,
    LINEAR
};

enum TextureWrap
{
    REPEAT,
    MIRROR_REPEAT,
    CLAMP_TO_EDGE,
    CLAMP_TO_BORDER
};

struct TextureParameter
{
    TextureFilter minFilter = NEAREST;
    TextureFilter magFilter = NEAREST;
    TextureWrap wrapX = REPEAT;
    TextureWrap wrapY = REPEAT;
    bool generateMipmap = false;
};

class Texture
{
  public:
    Texture(const Image &image);
    Texture(unsigned char *data, const glm::uvec2 &size, ImageFormat format = RGBA);
    Texture();
    void SetTextureParameter(const TextureParameter &parameter);
    TextureParameter GetTextureParameter() const;
    void Create(unsigned char *data, const glm::uvec2 &size, ImageFormat format = RGBA);
    void Create(const Image &image);
    void Select(uint32_t slot) const;
    void Deselect() const;

  private:
    uint32_t mId = 0;
    glm::uvec2 mSize = glm::uvec2(0, 0);
    TextureParameter mParameter;
    static uint32_t mSeletedId;
};
