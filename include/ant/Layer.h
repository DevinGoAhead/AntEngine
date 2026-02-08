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

    virtual void OnUpdate() {}

    virtual void OnDetach() {}

    /*
     * 其他层也有渲染出自己 UI 的需求, 如操作面板
     * ImguiLayer 不需要知道其它层的存在, 它只需要完成 begin / end, 其它层自己完成 Render
     * 这也是单独的将 ImguiLayer的 OnUpdate 拆开为 begin / end / Render
     * - 然后在 Applicable 中单独管理 begin / end, 而 Render 人仍然在 LayerStack 中管理的原因
     */
    virtual void OnImGuiRender() {} 

    virtual void OnEvent([[maybe_unused]] Event& event) {}

    const std::string& GetName() { return layerName; }

   protected:
    std::string layerName;
};
}  // namespace AE
