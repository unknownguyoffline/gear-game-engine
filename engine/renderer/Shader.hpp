#pragma once
#include <glm/glm.hpp>

class Shader
{
  public:
    void Select();
    void Deselect();
    void Create(const char *vertexShaderCode, const char *fragmentShaderCode);
    void SetUniformFloat(float value, const char *uniformName);
    void SetUniformVec2(const glm::vec2 &value, const char *uniformName);
    void SetUniformVec3(const glm::vec3 &value, const char *uniformName);
    void SetUniformVec4(const glm::vec4 &value, const char *uniformName);
    void SetUniformInt(int value, const char *uniformName);
    void SetUniformIVec2(const glm::ivec2 &value, const char *uniformName);
    void SetUniformIVec3(const glm::ivec3 &value, const char *uniformName);
    void SetUniformIVec4(const glm::ivec4 &value, const char *uniformName);
    void SetUniformMat4(const glm::mat4 &value, const char *uniformName);
    void SetUniformMat3(const glm::mat3 &value, const char *uniformName);
    int GetUniformLocation(const char *uniformName);

  private:
    uint32_t mId = 0;
    static uint32_t mSeletedId;
};
