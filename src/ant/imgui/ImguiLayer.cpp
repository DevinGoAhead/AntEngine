
#include "ant/imgui/ImguiLayer.h"
#include "GLFW/glfw3.h"
#include "ant/Ant.h"
#include "ant/AntPCH.h"  // IWYU pragma: keep
#include "platform/windows/WindowsWindow.h" // IWYU pragma: keep

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace AE {
void ImguiLayer::OnAttach() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    auto& io = ImGui::GetIO();

    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiBackendFlags_HasGamepad;

    io.ConfigFlags |=
        ImGuiConfigFlags_DockingEnable;  // IF using Docking Branch

    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;  // Eneble Viewports
    io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;
    io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;

    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    ImGui::StyleColorsDark();  //set style
    

    if ((io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0) {
        auto style = ImGui::GetStyle();
        style.WindowRounding = 0.F; // 当拖拽到原始窗口外, 不使用圆角
        style.Colors[ImGuiCol_WindowBg].w = 1.F; // 当拖拽到原始窗口外, 完全不透明
    }

    // Setup Platform/Renderer backends
    auto* myWindow = Application::Get()->GetWidnow().GetNativeWindow();
    ANT_CORE_ASSERT((myWindow != nullptr), "NativeWindow is null");

    // false: imgui will not set glfwCallbak
    ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(myWindow), true);
    ImGui_ImplOpenGL3_Init("#version 460");
}

void ImguiLayer::OnDetach() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImguiLayer::OnImGuiRender() {
    // 只有第 1 帧的时候初始化, 后面跳过
    // 后面每一帧使用的值都将是上一帧 ShowDemoWindow 所设置的值
    static bool show = true;
    ImGui::ShowDemoWindow(&show);
}

void ImguiLayer::OnEvent([[maybe_unused]] Event& event) {
    if (blockEvent) {  // 此时将允许 imgui 拦截事件,
        auto io = ImGui::GetIO();
        // 只在鼠标键盘相关事件中, 且 imgui 确实想要拦截的时候才会拦截, 否则穿透 imgui, 其它层会继续响应该 event
        event.bHandled |=
            (event.IsInCategory(EventCategory::Type::EventCategoryMouse) &&
             io.WantCaptureMouse);
        event.bHandled |=
            (event.IsInCategory(EventCategory::Type::EventCategoryKeyboard) &&
             io.WantCaptureKeyboard);
    }
}

void ImguiLayer::Begin() {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImguiLayer::End() {
    auto io = ImGui::GetIO();
    const auto& nativeWindow = Application::Get()->GetWidnow();
    io.DisplaySize = {static_cast<float>(nativeWindow.GetWidth()),
                      static_cast<float>(nativeWindow.GetHeight())};

    // Rendering
    // (Your code clears your framebuffer, renders your other stuff etc.)
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if ((io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0) {
        auto* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}

}  // namespace AE