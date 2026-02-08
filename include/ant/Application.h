#pragma once

#include "ant/Core.h"
#include "ant/LayerStack.h"
#include "ant/Window.h"

#include <memory>

namespace AE {

class WindowCloseEvent;
class WindowResizeEvent;
class Layer;

class ANT_API Application {
   public:
    Application(const Application& other) = delete;
    Application& operator=(const Application& other) = delete; 
    virtual ~Application();

    void AddStage(Layer* stage);
    void AddOverlay(Layer* overlay);
    void Run();
    const Window& GetWidnow() const {return *window;}
    static const Application* Get();
   protected:
    Application();

   private:
    void OnEvent(Event& event);
    bool OnWindowClose(WindowCloseEvent& windowCloseEvent);
    bool OnWindowResize(WindowResizeEvent& windowResizeEvent);

   private:
    bool isRunning = true;
    std::unique_ptr<Window> window;
    class ImguiLayer* imguiLayer;
    inline static Application* instance = nullptr;
    LayerStack layerStack;
};

// Implementation in client
std::unique_ptr<Application> CreateApplication();
}  // namespace AE