#pragma once

#include "ant/Core.h"
#include "ant/Layer.h"

namespace AE {
class ANT_API ImguiLayer : public Layer {
   public:
    ImguiLayer(std::string inLayerName) : Layer(std::move(inLayerName)) {}

    void OnAttach() override;

    void OnUpdate() override;

    void OnDetach() override;

    void OnImGuiRender() override;

    void OnEvent([[maybe_unused]] Event& event) override;

   private:
    bool blockEvent;
};
}  // namespace AE