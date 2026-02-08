#pragma once
// IWYU pragma: begin_exports
#include "ant/PlatformDetection.h"
// IWYU pragma: end_exports

#define BIT(x) 1U << x

#define ANT_BIND_EVENT_FN(fn)                                   \
    [this](auto&&... args) -> decltype(auto) {                  \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }

#if defined IMGUI_API_EXPORT
#define IMGUI_API(dllexport)
#elif defined(IMGUI_API_IMPORT)
#define IMGUI_API(dllimport)
#else
#define IMGUI_API
#endif