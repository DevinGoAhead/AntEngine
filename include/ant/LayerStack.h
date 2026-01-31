#include "ant/Core.h"
#include "cstdint"
#include "vector"

namespace AE {
class Layer;

enum LayerType : std::uint8_t { Stage, Overlay };

class ANT_API LayerStack {
   private:
    using MType = std::vector<Layer*>;

   public:
    void AddStage(Layer* stage);
    void RemoveStage(Layer* stage);
    void AddOverlay(Layer* overlay);
    void RemoveOverlay(Layer* overlay);

    auto begin() -> MType::iterator { return layers.begin(); }

    auto end() -> MType::iterator { return layers.end(); }

    auto begin() const -> MType::const_iterator { return layers.begin(); }

    auto end() const -> MType::const_iterator { return layers.end(); }

    auto rbegin() -> MType::reverse_iterator { return layers.rbegin(); }

    auto rend() -> MType::reverse_iterator { return layers.rend(); }

    auto rbegin() const -> MType::const_reverse_iterator {
        return layers.rbegin();
    }

    auto rend() const -> MType::const_reverse_iterator { return layers.rend(); }

   private:
    auto StageEnd() { return layers.begin() + stageInsterIndex; }

   private:
    std::vector<Layer*> layers;
    std::uint32_t stageInsterIndex = 0;
};
}  // namespace AE