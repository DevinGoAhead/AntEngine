#include "platform/WindowsWindow.h"
#include "ant/AntPCH.h"
#include "ant/event/EventApplication.hpp"
#include "ant/event/KeyEvent.hpp"
#include "ant/event/MouseEvent.hpp"

#include "GLFW/glfw3.h"

namespace AE {
static bool isGLFW_Initialized = false;

WindowsWindow::WindowsWindow(const WindowProp &winProp){
    Initial(winProp);
}

// NOLINTNEXTLINE(readability-function-cognitive-complexity)
void WindowsWindow::Initial(const WindowProp& winProp) {
    data.width = winProp.width;
    data.height = winProp.height;
    data.title = winProp.title;

    if (!isGLFW_Initialized) {
        if (auto ok = glfwInit(); ok == 0) {
            ANT_CORE_ASSERT(false, "GLFW failed to initialize!");
        } else {
            isGLFW_Initialized = true;
        }
    }
    window = glfwCreateWindow(static_cast<int>(data.width),
                                           static_cast<int>(data.height),
                                           data.title.data(), nullptr, nullptr);

    ANT_CORE_ASSERT(window,
                    "glfwCreateWindow | failed to create window");

    ANT_LOG_CORE_INFO("Create window - title: {}, size: [{} * {}]", data.title,
                      data.width, data.height);

    glfwMakeContextCurrent(window);
    SetVSync(true);
    glfwSetWindowUserPointer(window, &data);

    /*
     * bind callback
     */
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width,
                                                int height) {
        if (auto* data =
                static_cast<WindowData*>(glfwGetWindowUserPointer(window))) {
            data->width = width;
            data->height = height;

            WindowResizeEvent windowResizeEvent{width, height};
            data->eventCallback(windowResizeEvent);  // call eventCallback
        }
    });

    glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
        if (auto* data =
                static_cast<WindowData*>(glfwGetWindowUserPointer(window))) {
            WindowCloseEvent windowCloseEvent{};
            data->eventCallback(windowCloseEvent);
        }
    });

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key,
                                         [[maybe_unused]] int scancode,
                                         int action,
                                         [[maybe_unused]] int mods) {
        if (auto* data =
                static_cast<WindowData*>(glfwGetWindowUserPointer(window))) {
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent keyPressedEvent{key, false};
                    data->eventCallback(keyPressedEvent);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent keyPressedEvent{key, true};
                    data->eventCallback(keyPressedEvent);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent keyReleasedEvent{key};
                    data->eventCallback(keyReleasedEvent);
                    break;
                }
                default: {
                    ANT_LOG_CORE_WARN("Key action is not supported");
                }
            }
        }
    });

    glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button,
                                                 int action,
                                                 [[maybe_unused]] int mods) {
        if (auto* data =
                static_cast<WindowData*>(glfwGetWindowUserPointer(window))) {
            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressed mouseBtPressedEvent{button};
                    data->eventCallback(mouseBtPressedEvent);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleased mouseBtReleasedEvent{button};
                    data->eventCallback(mouseBtReleasedEvent);
                    break;
                }
                default: {
                    ANT_LOG_CORE_WARN("Mouse action is not supported");
                }
            }
        }
    });

    glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset,
                                            double yoffset) {
        if (auto* data =
                static_cast<WindowData*>(glfwGetWindowUserPointer(window))) {
            MouseScrolledEvent mouseScrolledEvent{static_cast<float>(xoffset),
                                                  static_cast<float>(yoffset)};
            data->eventCallback(mouseScrolledEvent);
        }
    });

    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos,
                                               double ypos) {
        if (auto* data =
                static_cast<WindowData*>(glfwGetWindowUserPointer(window))) {
            MouseMoveEvent mouseMoveEvent{static_cast<float>(xpos),
                                          static_cast<float>(ypos)};
            data->eventCallback(mouseMoveEvent);
        }
    });
}

 void WindowsWindow::SetEventCallback(const EventCallback& callback){
    data.eventCallback = callback;
 }
void WindowsWindow::SetVSync(bool enable) {
    if (enable) {
        glfwSwapInterval(1);
    } else {
        glfwSwapInterval(0);
    }
    data.isVSync = enable;
}

void WindowsWindow::OnUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void WindowsWindow::ShutDown() {
    glfwTerminate();
}
}  // namespace AE
