#include "Console.hpp"
#include "platform/ConsoleColor.hpp"
#include <string.h>

bool hasError(const String &string)
{
    bool argumentStart = false;
    for (int i = 0; i < string.size(); i++)
    {
        if (string[i] == '{' && argumentStart == false)
        {
            argumentStart = true;
            continue;
        }
        if (string[i] == '}')
        {
            argumentStart = false;
            continue;
        }

        if (string[i] == '{' && argumentStart)
        {
            printf("format_error: expected \'}\' after \'{\' [%s]", string.c_str());
            return true;
        }
        if (string[i] == '\0' && argumentStart)
        {
            printf("format_error: expected \'}\' after \'{\' [%s]", string.c_str());
            return true;
        }
        if (string[i] == '\n' && argumentStart)
        {
            printf("format_error: expected \'}\' after \'{\' [%s]", string.c_str());
            return true;
        }
    }
    if (argumentStart == true)
    {
        printf("format_error: expected \'}\' after \'{\' [%s]", string.c_str());
        return true;
    }

    return false;
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
    if (hasError(message))
        return;
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
            else if (subword == "float")
                printf("%f", va_arg(list, double));
            else if (subword == "bool")
                printf("%s", va_arg(list, int) ? "true" : "false");
            else if (subword == "string")
                printf("%s", va_arg(list, const char *));
            else if (subword == "pointer")
                printf("%p", va_arg(list, void *));
            else
                printf("logging_error: invalid type [%s]", subword.c_str());
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
    for (int i = 0; i < end.size(); i++)
    {
        if (end[i] == '\n')
        {
            resetConsoleColor();
            printf("\n");
            break;
        }
        printf("%c", end[i]);
    }
    va_end(list);
}
