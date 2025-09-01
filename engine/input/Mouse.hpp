#pragma once
#include <glm/glm.hpp>

struct Mouse
{
    static glm::vec2 position;
    static glm::vec2 offset;
    static glm::vec2 scrollOffset;
    static bool leftPress;
    static bool rightPress;
    static bool middlePress;
    static bool leftRelease;
    static bool rightRelease;
    static bool middleRelease;
    static bool hideCursor;

    static void reset();
};

inline glm::vec2 Mouse::position = glm::vec2(0);
inline glm::vec2 Mouse::scrollOffset = glm::vec2(0);
inline glm::vec2 Mouse::offset = glm::vec2(0);
inline bool Mouse::leftPress = false;
inline bool Mouse::rightPress = false;
inline bool Mouse::middlePress = false;
inline bool Mouse::leftRelease = false;
inline bool Mouse::rightRelease = false;
inline bool Mouse::middleRelease = false;
inline bool Mouse::hideCursor = false;