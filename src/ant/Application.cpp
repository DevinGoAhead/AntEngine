#include "ant/Application.h"
#include <GLFW/glfw3.h>
#include "ant/event/EventApplication.hpp"

#define ANT_BIND_EVENT_FN(fn)                                   \
    [this](auto&&... args) -> decltype(auto) {                  \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }

namespace AE {
Application::Application() {
    window = Window::CreateWindow({});
    window->SetEventCallback(ANT_BIND_EVENT_FN(OnEvent));
}

void Application::OnEvent(Event& event) {
    ANT_LOG_CORE_TRACE("{}", event.ToString());

    EventDispatcher eventDispather(event);
    eventDispather.Dispatch<WindowCloseEvent>(ANT_BIND_EVENT_FN(OnWindowClose));
    eventDispather.Dispatch<WindowResizeEvent>(
        ANT_BIND_EVENT_FN(OnWindowResize));
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

void Application::Run() {
    while (isRunning) {
        glClearColor(0.2, 0.5, 0.8, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
        if (window) {
            window->OnUpdate();
        }
    }
}
}  // namespace AE