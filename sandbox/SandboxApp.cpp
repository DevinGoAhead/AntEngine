#include "ant/Ant.h"
#include "ant/Layer.h"
#include "ant/imgui/ImguiLayer.h"

using namespace AE;

class MyLayer : public AE::Layer {
   public:
    MyLayer() = default;

    MyLayer(std::string inLayerName) : Layer(std::move(inLayerName)) {}

    void OnEvent(Event& e) override { ANT_LOG_TRACE("MyLayer OnEvent"); }

    void OnUpdate() override { ANT_LOG_TRACE("MyLayer OnUpdate"); }
};

class SandboxApp : public AE::Application {
   public:
    SandboxApp() { 
        AddStage(new MyLayer{"Mylayer"}); 
        AddStage(new ImguiLayer{"Imgui Layer"});
    }

    ~SandboxApp() override = default;
};

namespace AE {
std::unique_ptr<Application> CreateApplication() {
    return std::make_unique<SandboxApp>();
}
}  // namespace AE
