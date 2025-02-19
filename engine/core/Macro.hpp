#pragma once
#include <stdio.h>

#define ENABLE_PRINT_MACROS 1

#if ENABLE_PRINT_MACROS

#define CORE_LOG(...)                                                                                                  \
    printf("log: ");                                                                                                   \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");
#define CORE_WARN(...)                                                                                                 \
    printf("warn: ");                                                                                                  \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");
#define CORE_ERROR(...)                                                                                                \
    printf("error: ");                                                                                                 \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");
#define CORE_FATAL(...)                                                                                                \
    printf("fatal: ");                                                                                                 \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");

#define CLIENT_LOG(...)                                                                                                \
    printf("log: ");                                                                                                   \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");
#define CLIENT_WARN(...)                                                                                               \
    printf("warn: ");                                                                                                  \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");
#define CLIENT_ERROR(...)                                                                                              \
    printf("error: ");                                                                                                 \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");
#define CLIENT_FATAL(...)                                                                                              \
    printf("fatal: ");                                                                                                 \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n");

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
