#pragma once

#include "ant/Core.h"
#include "ant/Window.h"

struct GLFWwindow;

namespace AE {
class WindowsWindow : public Window {
   public:
    WindowsWindow(const WindowProp& winProp);
   
    void SetVSync(bool enable) override;
    void SetEventCallback(const EventCallback& callback) override;
    void OnUpdate() override;
    void ShutDown()override;

    bool IsVSync() const override { return data.isVSync; }
    std::uint32_t GetWidth() const override {return data.width;}
    std::uint32_t GetHeight() const override {return data.height;}
    std::string GetTitle() const override {return data.title;}
    void* GetNativeWindow() const override {return window;}

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
    GLFWwindow* window = nullptr;
};
}  // namespace AE
