#pragma once

#include "ant/Core.h"
#include "ant/Window.h"
#include "ant/LayerStack.h"

#include <memory>

namespace AE {

class WindowCloseEvent;
class WindowResizeEvent;
class Layer;

class ANT_API Application {
   public:
    Application();
    void AddStage(Layer* stage);
    void AddOverlay(Layer* overlay);
    virtual ~Application() = default;
    void Run();

   private:
    void OnEvent(Event& event);
    bool OnWindowClose(WindowCloseEvent& windowCloseEvent);
    bool OnWindowResize(WindowResizeEvent& windowResizeEvent);

   private:
    bool isRunning = true;
    std::unique_ptr<Window> window;
    LayerStack layerStack;

};

// Implementation in client
std::unique_ptr<Application> CreateApplication();
}  // namespace AE