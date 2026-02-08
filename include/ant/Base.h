#pragma once
// IWYU pragma: begin_exports
#include "ant/PlatformDetection.h"
// IWYU pragma: end_exports

#define BIT(x) 1U << x

#define ANT_BIND_EVENT_FN(fn)                                   \
    [this](auto&&... args) -> decltype(auto) {                  \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }

#ifdef IMGUI_API
#undef IMGUI_API
#endif

#if defined IMGUI_API_EXPORT
#define IMGUI_API __declspec(dllexport)
#elif defined(IMGUI_API_IMPORT)
#define IMGUI_API __declspec(dllimport)
#else
#define IMGUI_API
#endif