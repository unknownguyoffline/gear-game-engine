#include "platform/ConsoleColor.hpp"
#include <stdio.h>

void setConsoleTextColor(uint8_t r, uint8_t g, uint8_t b)
{
    printf("\e[38;2;%d;%d;%dm", r, g, b);
}
void setConsoleBackgroundColor(uint8_t r, uint8_t g, uint8_t b)
{
    printf("\e[48;2;%d;%d;%dm", r, g, b);
}
void resetConsoleColor()
{
    printf("\033[0m");
}
