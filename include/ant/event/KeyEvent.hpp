#pragma once

#include "Event.hpp"
#include "format"

namespace AE {
class ANT_API KeyEvent : public Event {
   protected:
    KeyEvent(int inKeyCode) : keyCode(inKeyCode) {}

    CLASS_EVENT_CATEGORY_TYPE(EventCategory::Type::EventCategoryInput |
                              EventCategory::Type::EventCategoryKeyboard)
   protected:
    int keyCode;
};

class ANT_API KeyPressedEvent : public KeyEvent {
   public:
    using KeyEvent::KeyEvent;

    std::string ToString() const override {
        return std::format("Key: [{}] is pressed, Repeat: [{}]", keyCode,
                           isRepeat);
    }

    CLASS_EVENT_TYPE(EventType::KeyPressed)

   private:
    bool isRepeat;
};

class ANT_API KeyReleasedEvent : public KeyEvent {
   public:
    using KeyEvent::KeyEvent;

    std::string ToString() const override {
        return std::format("Key: [{}] is released", keyCode);
    }

    CLASS_EVENT_TYPE(EventType::KeyReleased)
};

}  // namespace AE