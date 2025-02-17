#pragma once
#include <stdio.h>

#define ENABLE_PRINT_MACROS 1

#if ENABLE_PRINT_MACROS

#define CORE_LOG(...) printf(__VA_ARGS__);
#define CORE_WARN(...) printf(__VA_ARGS__);
#define CORE_ERROR(...) printf(__VA_ARGS__);
#define CORE_FATAL(...) printf(__VA_ARGS__);

#define CLIENT_LOG(...) printf(__VA_ARGS__);
#define CLIENT_WARN(...) printf(__VA_ARGS__);
#define CLIENT_ERROR(...) printf(__VA_ARGS__);
#define CLIENT_FATAL(...) printf(__VA_ARGS__);

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
