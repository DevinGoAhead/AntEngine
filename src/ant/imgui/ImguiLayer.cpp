
#include "ant/imgui/ImguiLayer.h"
#include "ant/AntPCH.h"  // IWYU pragma: keep
#include "ant/Ant.h"
#include "platform/WindowsWindow.h"

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
    io.ConfigFlags |=
        ImGuiConfigFlags_DockingEnable;  // IF using Docking Branch
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    // Setup Platform/Renderer backends
    auto* myWindow = Application::Get()->GetWidnow().GetNativeWindow();
    ANT_CORE_ASSERT((myWindow != nullptr), "NativeWindow is null");

    // false: imgui will not set glfwCallbak
    ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(myWindow), true);
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

}  // namespace AE