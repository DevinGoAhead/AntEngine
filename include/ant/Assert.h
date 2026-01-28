#pragma once

#include "ant/PlatformDetection.h"

#ifdef ANT_PLATFORM_WINDOWS
#define ANT_DEBUG_BREAK() __debugbreak()
#elif defined(ANT_PLATFORM_LINUX)
#define ANT_DEBUG_BREAK() __builtin_trap()
#else
#error "Platform is not supported!"
#endif

#ifdef ANT_ENABLE_ASSERT
#define ANT_CORE_ASSERT(x, ...)                                   \
    {                                                             \
        if (!x) {                                                 \
            ANT_LOG_CORE_ERROR("Assertion falied: {0}", __VA_ARGS__); \
            ANT_DEBUG_BREAK();                                    \
        }                                                         \
    }
#define ANT_ASSERT(x, ...)                                   \
    {                                                        \
        if (!x) {                                            \
            ANT_LOG_ERROR("Assertion falied: {0}", __VA_ARGS__); \
            ANT_DEBUG_BREAK();                               \
        }                                                    \
    }
#else
#define ANT_CORE_ASSERT(x, ...)
#define ANT_ASSERT(x, ...)
#endif