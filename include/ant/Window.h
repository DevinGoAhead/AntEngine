#pragma once

#include "ant/Core.h"
#include "ant/event/Event.hpp"

#include <cstdint>
#include <string>

namespace AE {
struct WindowProp {
    std::uint32_t width;
    std::uint32_t height;
    std::string title;

    WindowProp(std::uint32_t inWidth = 1280., std::uint32_t inHeight = 1024.,
               std::string inTitle = "Ant Engine")
        : width(inWidth), height(inHeight), title(std::move(inTitle)) {}
};

class Window {
   public:
    using EventCallback = std::function<void(Event&)>;

   public:
    Window() = default;
    virtual ~Window() = default;
    virtual void SetVSync(bool enable) = 0;
    virtual void SetEventCallback(const EventCallback& callback) = 0;
    virtual void OnUpdate() = 0;
    virtual void ShutDown() = 0;

    virtual bool IsVSync() const = 0;
    virtual std::uint32_t GetWidth() const = 0;
    virtual std::uint32_t GetHeight() const = 0;
    virtual std::string GetTitle() const = 0;
    virtual void* GetNativeWindow() const = 0;

    static std::unique_ptr<Window> CreateAEWindow(
        const WindowProp& winProp);  // Factory
};
}  // namespace AE