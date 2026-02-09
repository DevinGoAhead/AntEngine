#pragma once
#include "ant/Core.h"

namespace AE {
class ANT_API GraphicsContext {
   public:
    virtual void Initial() = 0;
    virtual void Swapbuffers() = 0;
};
}  // namespace AE