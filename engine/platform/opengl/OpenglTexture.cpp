#include <glad/glad.h>
#include "renderer/Texture.hpp"

uint32_t Texture::mSeletedId = UINT32_MAX;

GLenum glFilters[] = {GL_NEAREST, GL_LINEAR};
GLenum glWrap[] = {GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER};
GLenum glFormat[] = {GL_RED, GL_RG, GL_RGB, GL_RGBA};

Texture::Texture(const Image &image)
{
    Create(image);
}
Texture::Texture(unsigned char *data, const glm::uvec2 &size, ImageFormat format)
{
    Create(data, size, format);
}
Texture::Texture()
{
}
void Texture::Create(const Image &image)
{
    Create(image.data, image.size, image.format);
}
void Texture::Create(unsigned char *data, const glm::uvec2 &size, ImageFormat format)
{
    mSize = size;
    glGenTextures(1, &mId);
    glBindTexture(GL_TEXTURE_2D, mId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glFilters[mParameter.magFilter]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glFilters[mParameter.minFilter]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, glWrap[mParameter.wrapX]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, glWrap[mParameter.wrapY]);
    glTexImage2D(GL_TEXTURE_2D, 0, glFormat[format], size.x, size.y, 0, glFormat[format], GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    mSeletedId = mId;
}
void Texture::Select(uint32_t slot) const
{
    if (mSeletedId == mId)
        return;
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, mId);
    glGenerateMipmap(GL_TEXTURE_2D);
    mSeletedId = mId;
}

void Texture::Deselect() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
    mSeletedId = UINT32_MAX;
}

void Texture::SetTextureParameter(const TextureParameter &parameter)
{
    mParameter = parameter;
}

TextureParameter Texture::GetTextureParameter() const
{
    return mParameter;
}
