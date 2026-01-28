#pragma once

#include "Event.hpp"

namespace AE {
// Abstract
class ApplicationEvent : public Event {
   public:
    CLASS_EVENT_CATEGORY_TYPE(EventCategory::Type::EventCategoryApplication)
};

class WindowCloseEvent : public ApplicationEvent {
   public:
    CLASS_EVENT_TYPE(EventType::WindowFocus)
};

class WindowResizeEvent : public ApplicationEvent {
   public:
    WindowResizeEvent(int inwidth, int inHeight)
        : width(inwidth), height(inHeight) {}

    [[nodiscard]] inline int GetWidth() const { return width; }

    [[nodiscard]] inline int GetHeight() const { return height; }

    std::string ToString() const override {
        return std::format("Resize window: [width: {}, height: {}]", width,
                           height);
    }
    CLASS_EVENT_TYPE(EventType::WindowResize)
   private:
    int width;
    int height;
};

class AppRenderEvent : public ApplicationEvent {
   public:
    CLASS_EVENT_TYPE(EventType::AppRender)
};

class AppUpdateEvent : public ApplicationEvent {
   public:
    CLASS_EVENT_TYPE(EventType::AppUpdate)
};
}  // namespace AE