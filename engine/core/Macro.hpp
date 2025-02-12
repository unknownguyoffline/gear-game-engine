#pragma once
#include "utility/Console.hpp"

#define ENABLE_PRINT_MACROS 1

#if ENABLE_PRINT_MACROS
inline Console __macro_console;

#define CORE_LOG(...)                                                                                                  \
    printf("core: ");                                                                                                  \
    __macro_console.log(__VA_ARGS__)
#define CORE_WARN(...)                                                                                                 \
    printf("core: ");                                                                                                  \
    __macro_console.warn(__VA_ARGS__)
#define CORE_ERROR(...)                                                                                                \
    printf("core: ");                                                                                                  \
    __macro_console.error(__VA_ARGS__)
#define CORE_FATAL(...)                                                                                                \
    printf("core: ");                                                                                                  \
    __macro_console.fatal(__VA_ARGS__)

#define CLIENT_LOG(...)                                                                                                \
    printf("client: ");                                                                                                \
    __macro_console.log(__VA_ARGS__)
#define CLIENT_WARN(...)                                                                                               \
    printf("client: ");                                                                                                \
    __macro_console.warn(__VA_ARGS__)
#define CLIENT_ERROR(...)                                                                                              \
    printf("client: ");                                                                                                \
    __macro_console.error(__VA_ARGS__)
#define CLIENT_FATAL(...)                                                                                              \
    printf("client: ");                                                                                                \
    __macro_console.fatal(__VA_ARGS__)

#else

#define CORE_LOG(...)
#define CORE_WARN(...)
#define CORE_ERROR(...)
#define CORE_FATAL(...)

#define CLIENT_LOG(...)
#define CLIENT_WARN(...)
#define CLIENT_ERROR(...)
#define CLIENT_FATAL(...)
#endif
