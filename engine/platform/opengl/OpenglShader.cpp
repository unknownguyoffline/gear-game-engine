#include "renderer/Shader.hpp"
#include "core/Macro.hpp"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

uint32_t Shader::mSeletedId = UINT32_MAX;

uint32_t createShader(const char *code, GLenum shaderType)
{
    uint32_t shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);
    return shader;
}
uint32_t createProgram(uint32_t vertexShader, uint32_t fragmentShader)
{
    uint32_t program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    return program;
}

void validateShader(uint32_t shader, const char *errorFormat)
{
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        CORE_ERROR(errorFormat, infoLog);
    }
}
void validateProgram(uint32_t program, const char *errorFormat)
{
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        CORE_ERROR(errorFormat, infoLog);
    }
    assert(success);
}

void Shader::Create(const char *vertexShaderCode, const char *fragmentShaderCode)
{
    uint32_t vertexShader = createShader(vertexShaderCode, GL_VERTEX_SHADER);
    uint32_t fragmentShader = createShader(fragmentShaderCode, GL_FRAGMENT_SHADER);
    mId = createProgram(vertexShader, fragmentShader);

    validateShader(vertexShader, "Vertex shader error: %s");
    validateShader(fragmentShader, "Fragment shader error: %s");
    validateProgram(mId, "Shader program error: %s");
}

void Shader::Select()
{
    // if (mSeletedId != mId)
    //     return;
    glUseProgram(mId);
    mSeletedId = mId;
}

void Shader::Deselect()
{
    glUseProgram(0);
    mSeletedId = UINT_MAX;
}

void Shader::SetUniformFloat(float value, const char *uniformName)
{
    glUniform1f(GetUniformLocation(uniformName), value);
}

void Shader::SetUniformVec2(const glm::vec2 &value, const char *uniformName)
{
    glUniform2f(GetUniformLocation(uniformName), value.x, value.y);
}

void Shader::SetUniformVec3(const glm::vec3 &value, const char *uniformName)
{
    glUniform3f(GetUniformLocation(uniformName), value.x, value.y, value.z);
}

void Shader::SetUniformVec4(const glm::vec4 &value, const char *uniformName)
{
    glUniform4f(GetUniformLocation(uniformName), value.x, value.y, value.z, value.w);
}

void Shader::SetUniformInt(int value, const char *uniformName)
{
    glUniform1i(GetUniformLocation(uniformName), value);
}

void Shader::SetUniformIVec2(const glm::ivec2 &value, const char *uniformName)
{
    glUniform2i(GetUniformLocation(uniformName), value.x, value.y);
}

void Shader::SetUniformIVec3(const glm::ivec3 &value, const char *uniformName)
{
    glUniform3i(GetUniformLocation(uniformName), value.x, value.y, value.z);
}

void Shader::SetUniformIVec4(const glm::ivec4 &value, const char *uniformName)
{
    glUniform4i(GetUniformLocation(uniformName), value.x, value.y, value.z, value.w);
}

void Shader::SetUniformMat4(const glm::mat4 &value, const char *uniformName)
{
    glUniformMatrix4fv(GetUniformLocation(uniformName), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetUniformMat3(const glm::mat3 &value, const char *uniformName)
{
    glUniformMatrix3fv(GetUniformLocation(uniformName), 1, GL_FALSE, glm::value_ptr(value));
}

int32_t Shader::GetUniformLocation(const char *uniformName)
{
    int uniformLocation = glGetUniformLocation(mId, uniformName);
    if (uniformLocation == -1)
    {
        CORE_ERROR("uniform not found [%s]", uniformName);
    }
    return uniformLocation;
}
