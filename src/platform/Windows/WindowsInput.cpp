#include "platform/windows/WindowsInput.h"
#include "ant/Ant.h"
#include "GLFW/glfw3.h"

namespace AE {
    Input* Input::instance = new WindowsInput{};
bool WindowsInput::IsKeyPressed_Impl(int keyCode) {
    auto* window = static_cast<GLFWwindow*>(
        Application::Get()->GetWidnow().GetNativeWindow());
    auto lastKeyState = glfwGetKey(window, keyCode);
    return lastKeyState == GLFW_PRESS;
}

bool WindowsInput::IsMouseButtonPressed_Impl(int mouseButtonCode) {
    auto* window = static_cast<GLFWwindow*>(
        Application::Get()->GetWidnow().GetNativeWindow());
    auto lastButtonState = glfwGetMouseButton(window, mouseButtonCode);
    return lastButtonState == GLFW_PRESS;
}

std::pair<float, float> WindowsInput::GetMousePosImpl() {
    auto* window = static_cast<GLFWwindow*>(
        Application::Get()->GetWidnow().GetNativeWindow());
    double xPos;
    double yPos;
    glfwGetCursorPos(window, &xPos, &yPos);
    return {static_cast<float>(xPos), static_cast<float>(yPos)};
}

float WindowsInput::GetMouseX_Impl() {
    return GetMousePosImpl().first;
}

float WindowsInput::GetMouseY_Impl() {
    return GetMousePosImpl().second;
}

};  // namespace AE