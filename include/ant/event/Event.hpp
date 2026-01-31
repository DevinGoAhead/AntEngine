#pragma once

#include "ant/Core.h"
#include "ant/Log.h"
#include <cstdint>
#include "ant/AntPCH.h"

namespace AE {

enum class EventType : std::uint8_t {
    None = 0,
    WindowClose,
    WindowResize,
    WindowFocus,
    WindowLostFocus,
    WindowMoved,
    AppTick,
    AppUpdate,
    AppRender,
    KeyPressed,
    KeyReleased,
    KeyTyped,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
};

namespace EventCategory {
enum Type : std::uint8_t {
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyboard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseButton = BIT(4)
};
}

#define CLASS_EVENT_TYPE(type)                                    \
    [[nodiscard]] static EventType GetStaticType() {              \
        return type;                                              \
    }                                                             \
    [[nodiscard]] EventType GetEventType() const override {       \
        return GetStaticType();                                   \
    }                                                             \
    [[nodiscard]] std::string_view GetTypeName() const override { \
        return #type; /* 常量, 静态区 */                     \
    }

#define CLASS_EVENT_CATEGORY_TYPE(category) \
    int GetEventCategory() const override { \
        return category;                    \
    }

class ANT_API Event {
   public:
    Event() = default;
    virtual ~Event() = default;
    virtual EventType GetEventType() const = 0;
    virtual std::string_view GetTypeName() const = 0;
    virtual int GetEventCategory() const = 0;

    virtual std::string ToString() const { return GetTypeName().data(); }

   public:
    bool bHandled = false;
};

class ANT_API EventDispatcher {
   public:
    EventDispatcher(Event& inEvent) : event(inEvent) {}

    template <typename EventT, typename CallbackT>
    bool Dispatch(CallbackT Func) {
        /**
         * event 需要引用一个对象, class Event 不可能被实例化, 自然 event 引用的一定是 class Event 的子类
         * EventT::GetStaticType() 确保 EventT 是 Event 的子类类型并且实现了 GetStaticType(), 否则编译报错
         * == 则确保二者类型一致, 确保后续的 static_cast 是安全的
         */
        if (event.GetEventType() == EventT::GetStaticType()) {
            event.bHandled |= Func(static_cast<EventT&>(event));
            return true;
        }
        return false;
    }

   private:
    Event& event;  // 强制要求 event 必须被有效初始化
};
}  // namespace AE