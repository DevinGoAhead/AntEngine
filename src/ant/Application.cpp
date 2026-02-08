#include "ant/Application.h"
#include "ant/Ant.h"
#include "ant/AntPCH.h"
#include "ant/Input.hpp"
#include "ant/Layer.h"
#include "ant/event/EventApplication.hpp"
#include "ant/imgui/ImguiLayer.h"

#include "GLFW/glfw3.h"  // IWYU pragma: keep local

//#include "glm/glm.hpp"

namespace AE {
Application::Application() {
    ANT_CORE_ASSERT((instance == nullptr), "Application already exists!");

    window = AE::Window::CreateAEWindow({});
    window->SetEventCallback(ANT_BIND_EVENT_FN(OnEvent));
    instance = this;

    imguiLayer = new ImguiLayer("Imgui");
    AddOverlay(imguiLayer);
}

const Application* Application::Get() {
    if (instance == nullptr) {
        Application();
    }
    return instance;
}

void Application::Run() {
    while (isRunning) {
        glClearColor(0.2F, 0.5F, 0.8F, 1.F);
        glClear(GL_COLOR_BUFFER_BIT);

        // 这部分参见 Layer::OnImGuiRender 函数的注释

        for (const auto& layer : layerStack) {
            layer->OnUpdate();
        }

        imguiLayer->Begin();
        for (const auto& layer : layerStack) {
            layer->OnImGuiRender();
        }
        imguiLayer->End();

        auto [x, y] = Input::GetMousePos();
        ANT_LOG_CORE_TRACE("Mouse Position: [{}, {}]", x, y);

        if (window) {
            window->OnUpdate();
        }
    }
}

Application::~Application() {
    delete imguiLayer;
}

void Application::AddStage(Layer* stage) {
    layerStack.AddStage(stage);
    stage->OnAttach();
}

void Application::AddOverlay(Layer* overlay) {
    layerStack.AddOverlay(overlay);
    overlay->OnAttach();
}

void Application::OnEvent(Event& event) {
    ANT_LOG_CORE_TRACE("{}", event.ToString());

    EventDispatcher eventDispather(event);
    // 只有这两个由 Ant Engine 控制, 并且会将 bHandeld 置为 true, 此时其他层的这俩事件 (假设有) 将不会得到响应
    eventDispather.Dispatch<WindowCloseEvent>(ANT_BIND_EVENT_FN(OnWindowClose));
    eventDispather.Dispatch<WindowResizeEvent>(
        ANT_BIND_EVENT_FN(OnWindowResize));
    // imgui 会接管诸多事件,  imgui 内部依然会备份并执行 Ant 所设置的 glfw 回调
    for (auto* layer : layerStack | std::views::reverse) {
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