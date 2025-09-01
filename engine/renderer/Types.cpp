#include "Types.hpp"
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 getModelMatrix(const Transform &transform)
{
    glm::mat4 model = glm::mat4(1.f);
    model = glm::translate(model, transform.position);
    model = glm::rotate(model, glm::radians(transform.rotation.x), glm::vec3(1, 0, 0));
    model = glm::rotate(model, glm::radians(transform.rotation.y), glm::vec3(0, 1, 0));
    model = glm::rotate(model, glm::radians(transform.rotation.z), glm::vec3(0, 0, 1));
    model = glm::scale(model, transform.scale);
    return model;
}
