#pragma once

// IWYU pragma: begin_exports

#include "ant/PlatformDetection.h"  

#ifdef ANT_PLATFORM_WINDOWS
#ifndef NOMINMAX
// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#define NOMINMAX
#endif
#endif

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>
#include <format>
#include <ranges>

#include <array>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cstdint>

#include "ant/Base.h"

#ifdef ANT_PLATFORM_WINDOWS
#include <Windows.h>
#endif

// IWYU pragma: end_exports
