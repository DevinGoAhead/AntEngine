#pragma once

#include "ant/Core.h"
#include "ant/Window.h"

class GLFWwindow;

namespace AE {
class WindowsWindow : public Window {
   public:
    WindowsWindow(const WindowProp& winProp);
   
    void SetVSync(bool enable) override;
    void SetEventCallback(const EventCallback& callback) override;
    void OnUpdate() override;
    void ShutDown()override;

    bool IsVSync() override { return data.isVSync; }
    std::uint32_t GetWidth() override {return data.width;}
    std::uint32_t GetHeight() override {return data.height;}
    std::string GetTitle() override {return data.title;}

   private:
    void Initial(const WindowProp& winProp);

   private:
    struct WindowData {
        std::uint32_t width;
        std::uint32_t height;
        std::string title;
        bool isVSync;
        EventCallback eventCallback;
    };

    WindowData data;
    GLFWwindow* window;
};
}  // namespace AE
