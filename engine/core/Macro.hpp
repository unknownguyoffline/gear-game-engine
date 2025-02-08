#pragma once
#include "utility/Console.hpp"

#define ENABLE_PRINT_MACROS 1

#if ENABLE_PRINT_MACROS
inline Console __macro_console;

#define CORE_LOG(message, ...)                                                                                         \
    printf("core: ");                                                                                                  \
    __macro_console.log(message, __VA_ARGS__)
#define CORE_WARN(message, ...)                                                                                        \
    printf("core: ");                                                                                                  \
    __macro_console.warn(message, __VA_ARGS__)
#define CORE_ERROR(message, ...)                                                                                       \
    printf("core: ");                                                                                                  \
    __macro_console.error(message, __VA_ARGS__)
#define CORE_FATAL(message, ...)                                                                                       \
    printf("core: ");                                                                                                  \
    __macro_console.fatal(message, __VA_ARGS__)

#define CLIENT_LOG(message, ...)                                                                                       \
    printf("client: ");                                                                                                \
    __macro_console.log(message, __VA_ARGS__)
#define CLIENT_WARN(message, ...)                                                                                      \
    printf("client: ");                                                                                                \
    __macro_console.warn(message, __VA_ARGS__)
#define CLIENT_ERROR(message, ...)                                                                                     \
    printf("client: ");                                                                                                \
    __macro_console.error(message, __VA_ARGS__)
#define CLIENT_FATAL(message, ...)                                                                                     \
    printf("client: ");                                                                                                \
    __macro_console.fatal(message, __VA_ARGS__)

#else

#define CORE_LOG(message, ...)
#define CORE_WARN(message, ...)
#define CORE_ERROR(message, ...)
#define CORE_FATAL(message, ...)

#define CLIENT_LOG(message, ...)
#define CLIENT_WARN(message, ...)
#define CLIENT_ERROR(message, ...)
#define CLIENT_FATAL(message, ...)
#endif
