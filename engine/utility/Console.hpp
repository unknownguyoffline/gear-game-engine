#pragma once
#include "utility/String.hpp"
#include <stdarg.h>

class Console
{
  public:
    void writeVa(const char *message, va_list list);

    void write(const char *message, ...);
    void log(const char *message, ...);
    void error(const char *message, ...);
    void warn(const char *message, ...);
    void fatal(const char *message, ...);

    String end = "\n";
};
