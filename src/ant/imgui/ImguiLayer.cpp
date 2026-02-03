
#include "ant/imgui/ImguiLayer.h"
#include "ant/AntPCH.h"  // IWYU pragma: keep
#include "ant/Application.h"
#include "platform/WindowsWindow.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace AE {
void ImguiLayer::OnAttach() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    auto& imguiIO = ImGui::GetIO();

    imguiIO.ConfigFlags |=
        ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    imguiIO.ConfigFlags |=
        ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    imguiIO.ConfigFlags |=
        ImGuiConfigFlags_DockingEnable;  // IF using Docking Branch
    imguiIO.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    imguiIO.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    // Setup Platform/Renderer backends
    auto* myWindow = Application::Get()->GetWidnow().GetNativeWindow();
    ANT_CORE_ASSERT((myWindow != nullptr), "NativeWindow is null");

    // false: imgui will not set glfwCallbak
    ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(myWindow), false);
    ImGui_ImplOpenGL3_Init("#version 460");
}

void ImguiLayer::OnUpdate() {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow();  // Show demo window! :)

    // Rendering
    // (Your code clears your framebuffer, renders your other stuff etc.)
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // (Your code calls glfwSwapBuffers() etc.)
}

void ImguiLayer::OnDetach() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImguiLayer::OnImGuiRender() {}

void ImguiLayer::OnEvent([[maybe_unused]] Event& event) {
    // 假设你有这样的调度器
    // EventDispatcher dispatcher(e);

    // // 如果是鼠标按键事件，就手动调 ImGui 的处理函数
    // dispatcher.Dispatch<MouseButtonPressedEvent>([this](MouseButtonPressedEvent& e) {
    //     ImGui_ImplGlfw_MouseButtonCallback(window, e.GetButton(), GLFW_PRESS, 0);
    //     return false; // 是否拦截看你的需求
    // });

    // // 键盘事件同理
    // dispatcher.Dispatch<KeyPressedEvent>([this](KeyPressedEvent& e) {
    //     ImGui_ImplGlfw_KeyCallback(window, e.GetKeyCode(), GLFW_PRESS, 0, 0);
    //     return false;
    // });
}

}  // namespace AE