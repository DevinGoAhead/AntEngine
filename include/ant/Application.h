#pragma once

#include "Core.h"
#include "memory"

namespace AE {
class ANT_API Application {
   public:
    Application() = default;
    virtual ~Application() = default;
    void Run();
};

// Implementation in client
std::unique_ptr<Application> CreateApplication();
}  // namespace AE