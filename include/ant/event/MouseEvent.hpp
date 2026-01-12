#pragma once

#include "Event.hpp"

namespace AE {
class MouseMoveEvent : public Event {
   public:
    MouseMoveEvent(float x, float y) : xCoord(x), yCoord(y) {}

    [[nodiscard]] inline float GetXCoordinate() const { return xCoord; }

    [[nodiscard]] inline float GetYCoordinate() const { return yCoord; }

    CLASS_EVENT_TYPE(EventType::MouseMoved)
    CLASS_EVENT_CATEGORY_TYPE(EventCategory::Type::EventCategoryMouse)

    std::string ToString() const override {
        return std::format("Mouse's coordinates: [{}, {}]", xCoord, yCoord);
    }

   private:
    float xCoord;
    float yCoord;
};

class MouseScrolledEvent : public Event {
   public:
    MouseScrolledEvent(float x, float y) : xOffset(x), yOffset(y) {}

    [[nodiscard]] inline float GetXOffset() const { return xOffset; }

    [[nodiscard]] inline float GetYOffset() const { return yOffset; }

    CLASS_EVENT_TYPE(EventType::MouseScrolled)
    CLASS_EVENT_CATEGORY_TYPE(EventCategory::Type::EventCategoryMouse)

    std::string ToString() const override {
        return std::format("Mouse scrolled: [{}, {}]", xOffset, yOffset);
    }

   private:
    float xOffset;
    float yOffset;
};

class MouseButtonEvent : public Event {
   public:
    [[nodiscard]] inline int GetButtonCode() const { return buttonCode; }
    CLASS_EVENT_CATEGORY_TYPE(EventCategory::Type::EventCategoryMouse |
                              EventCategory::Type::EventCategoryMouseButton |
                              EventCategory::Type::EventCategoryInput)
   protected:
    MouseButtonEvent(int inButtonCode) : buttonCode(inButtonCode) {}

   protected:
    int buttonCode;
};

class MouseButtonPressed : public MouseButtonEvent {
   public:
    using MouseButtonEvent::MouseButtonEvent;
    CLASS_EVENT_TYPE(EventType::MouseButtonPressed)

    std::string ToString() const override {
        return std::format("Mouse Key [{}] is pressed", buttonCode);
    }
};

class MouseButtonReleased : public MouseButtonEvent {
   public:
    using MouseButtonEvent::MouseButtonEvent;
    CLASS_EVENT_TYPE(EventType::MouseButtonReleased)

    std::string ToString() const override {
        return std::format("Mouse Key [{}] is released", buttonCode);
    }
};
}  // namespace AE
