#include "Mouse.hpp"
#include "glm/glm.hpp"

void Mouse::reset()
{
    position = glm::vec2(0);
    scrollOffset = glm::vec2(0);
    offset = glm::vec2(0);
    leftPress = false;
    rightPress = false;
    middlePress = false;
    leftRelease = false;
    rightRelease = false;
    middleRelease = false;
    hideCursor = false;
}
