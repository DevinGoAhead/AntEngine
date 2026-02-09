#pragma once

#include "ant/Core.h"
#include "ant/Input.hpp"

namespace AE {
class WindowsInput : public Input {
   protected:
    bool IsKeyPressed_Impl(int keyCode) override;
    bool IsMouseButtonPressed_Impl(int mouseButtonCode) override;
    std::pair<float, float> GetMousePosImpl() override;
    float GetMouseX_Impl() override;
    float GetMouseY_Impl() override;
};

}  // namespace AE