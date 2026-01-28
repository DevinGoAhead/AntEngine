#pragma once

#include "ant/Core.h"
#include "ant/Window.h"

class GLFWwindow;

namespace AE {
class WindowWindow : public Window {
   public:
    WindowWindow(const WindowProp& winProp);
   
    void SetVSync(bool enable) override;
    void SetEventCallback(const EventCallback& callback) override;
    void OnUpdate() override;
    void ShutDown()override;

    inline bool IsVSync() override { return data.isVSync; }
    inline uint32_t GetWidth() override {return data.width;}
    inline uint32_t GetHeight() override {return data.height;}
    inline std::string GetTitle() override {return data.title;}

   private:
    void Initial(const WindowProp& winProp);

   private:
    struct WindowData {
        uint32_t width;
        uint32_t height;
        std::string title;
        bool isVSync;
        EventCallback eventCallback;
    };

    WindowData data;
    GLFWwindow* window;
};
}  // namespace AE
