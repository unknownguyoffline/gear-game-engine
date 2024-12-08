#include "Console.hpp"
#include "platform/ConsoleColor.hpp"
#include <string.h>

void checkFormat(const String &string)
{
}
void Console::write(const char *message, ...)
{
    va_list list;
    va_start(list, message);
    writeVa(message, list);
    va_end(list);
}
void Console::writeVa(const char *message, va_list list)
{
    String word;
    checkFormat(message);
    size_t stringSize = strlen(message);
    for (size_t i = 0; i < stringSize; i++)
    {
        if (message[i] == '{')
        {
            i++;
            String subword;
            while (message[i] != '}')
            {
                subword += message[i];
                i++;
            }
            if (subword == "int")
                printf("%d", va_arg(list, int));
            if (subword == "float")
                printf("%f", va_arg(list, double));
            if (subword == "bool")
                printf("%s", va_arg(list, int) ? "true" : "false");
            if (subword == "string")
                printf("%s", va_arg(list, const char *));
            i++;
        }
        printf("%c", message[i]);
    }
    fflush(stdout);
}

void Console::log(const char *message, ...)
{
    va_list list;
    setConsoleTextColor(136, 231, 136);
    va_start(list, message);
    writeVa(message, list);
    printf("%s", end.c_str());
    resetConsoleColor();
    va_end(list);
}

void Console::error(const char *message, ...)
{
    va_list list;
    setConsoleTextColor(255, 90, 95);
    va_start(list, message);
    writeVa(message, list);
    printf("%s", end.c_str());
    resetConsoleColor();
    va_end(list);
}
void Console::warn(const char *message, ...)
{
    va_list list;
    va_start(list, message);
    setConsoleTextColor(237, 211, 110);
    writeVa(message, list);
    printf("%s", end.c_str());
    resetConsoleColor();
    va_end(list);
}
void Console::fatal(const char *message, ...)
{
    va_list list;
    setConsoleBackgroundColor(255, 90, 95);
    setConsoleTextColor(237, 211, 110);
    va_start(list, message);
    writeVa(message, list);
    printf("%s", end.c_str());
    resetConsoleColor();
    va_end(list);
}
