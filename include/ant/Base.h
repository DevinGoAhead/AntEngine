#pragma once
// IWYU pragma: begin_exports
#include "ant/PlatformDetection.h"


#define BIT(x) 1U << x

#define ANT_BIND_EVENT_FN(fn)                                   \
    [this](auto&&... args) -> decltype(auto) {                  \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }


#include "ant/Log.h"
#include "ant/Assert.h"
// IWYU pragma: end_exports