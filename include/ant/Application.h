#pragma once
#include "AntAPI.h"

#include "memory"

namespace AT {
class ANT_API Application {
   public:
    Application() = default;
    virtual ~Application() = default;
    void Run();
};

// Implementation in client
std::unique_ptr<Application> CreateApplication();
}  // namespace AT