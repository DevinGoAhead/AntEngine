#pragma once

#include <utility>
#include "ant/Core.h"


namespace AE {
class ANT_API Input {
   public:
    static bool IsKeyPressed(int keyCode) {
        return instance->IsKeyPressed_Impl(keyCode);
    }

    static bool IsMouseButtonPressed(int mouseButtonCode) {
        return instance->IsMouseButtonPressed_Impl(mouseButtonCode);
    }

    static std::pair<float, float> GetMousePos() {
        return instance->GetMousePosImpl();
    }

    float GetMouseX() { return instance->GetMouseX_Impl(); }

    float GetMouseY() { return instance->GetMouseY_Impl(); }

   protected:
    virtual bool IsKeyPressed_Impl(int keyCode) = 0;
    virtual bool IsMouseButtonPressed_Impl(int mouseButtonCode) = 0;
    virtual std::pair<float, float> GetMousePosImpl() = 0;
    virtual float GetMouseX_Impl() = 0;
    virtual float GetMouseY_Impl() = 0;

   private:
    static Input* instance;
};
}  // namespace AE
