#pragma once

#include "ant/Core.h"
#include "string"

namespace AE {
class Event;

class ANT_API Layer {
   public:
    Layer() = default;

    Layer(std::string inLayerName) : layerName(std::move(inLayerName)) {}

    virtual ~Layer() {}

    virtual void OnAttach() {}

    virtual void OnDetach() {}

    virtual void OnUpdate() {}

    virtual void OnImGuiRender() {}

    virtual void OnEvent([[maybe_unused]] Event& event) {}

    const std::string& GetName() { return layerName; }

   protected:
    std::string layerName;
};
}  // namespace AE
