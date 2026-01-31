#include "ant/Application.h"
#include "ant/AntPCH.h"
#include "ant/Layer.h"
#include "ant/event/EventApplication.hpp"

#include <GLFW/glfw3.h>

#define ANT_BIND_EVENT_FN(fn)                                   \
    [this](auto&&... args) -> decltype(auto) {                  \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }

namespace AE {
Application::Application() {
    window = AE::Window::CreateAEWindow({});
    window->SetEventCallback(ANT_BIND_EVENT_FN(OnEvent));
}

void Application::Run() {
    while (isRunning) {
        glClearColor(0.2, 0.5, 0.8, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        for(const auto& layer : layerStack){
            layer->OnUpdate();
        }

        if (window) {
            window->OnUpdate();
        }
    }
}

void Application::AddStage(Layer* stage) {
    layerStack.AddStage(stage);
}

void Application::AddOverlay(Layer* overlay) {
    layerStack.AddOverlay(overlay);
}

void Application::OnEvent(Event& event) {
    ANT_LOG_CORE_TRACE("{}", event.ToString());

    EventDispatcher eventDispather(event);
    eventDispather.Dispatch<WindowCloseEvent>(ANT_BIND_EVENT_FN(OnWindowClose));
    eventDispather.Dispatch<WindowResizeEvent>(
        ANT_BIND_EVENT_FN(OnWindowResize));

    for (AE::Layer* layer : layerStack | std::views::reverse) {
        if (event.bHandled) {
            break;
        }
        layer->OnEvent(event);
    }
}

bool Application::OnWindowClose(
    [[maybe_unused]] WindowCloseEvent& windowCloseEvent) {
    isRunning = false;
    ANT_LOG_CORE_INFO("Succeed to close Window - {}", window->GetTitle());
    return true;
}

bool Application::OnWindowResize(WindowResizeEvent& windowResizeEvent) {

    ANT_LOG_CORE_TRACE("Window size: [{} * {}]", windowResizeEvent.GetWidth(),
                       windowResizeEvent.GetHeight());
    return true;
}

}  // namespace AE