#include "ant/LayerStack.h"
#include "ant/AntPCH.h"

#include "ant/Layer.h"

namespace AE {
void LayerStack::AddStage(Layer* stage) {
    if (stage != nullptr) {
        layers.emplace(StageEnd(), stage);
        ++stageInsterIndex;
    }
}

void LayerStack::RemoveStage(Layer* stage) {
    if (auto it = std::find(layers.begin(), StageEnd(), stage);
        it != StageEnd()) {
        (*it)->OnDetach();
        layers.erase(it);
        --stageInsterIndex;
    }
}

void LayerStack::AddOverlay(Layer* overlay) {
    layers.emplace_back(overlay);
}

void LayerStack::RemoveOverlay(Layer* overlay) {
    if (auto it = std::find(begin(), StageEnd(), overlay); it != layers.end()) {
        (*it)->OnDetach();
        layers.erase(it);
    }
}

}  // namespace AE