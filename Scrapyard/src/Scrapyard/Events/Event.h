#ifndef EVENT_H
#define EVENT_H

#include "Scrapyard/Core.h"
#include <string>
#include <functional>

namespace Scrapyard {

// Events are currently blocking - it is immediately dealt with once it is dispatched.

enum class EventType {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowFocusLost, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScroll
};

// Macro for getting and comparing static types. 
#define E_CLASS_TYPE(type)  static EventType getStaticType() {return EventType::type; } \
                            virtual EventType getEventType() const override { return getStaticType(); } \
                            virtual const char* getName() const override { return #type; }

// Macro for checking for class categories. 
#define E_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

// Event Category -> bitmasks.
enum E_Category {
    None = 0,
    Application  = BIT(0),
    Input        = BIT(1),
    Keyboard     = BIT(2),
    Mouse        = BIT(3),
    MouseButton  = BIT(4)
};

// Event class
class Event {
    
        friend class EventDispatcher;

    public:
        virtual EventType getEventType() const = 0;
        virtual const char* getName() const = 0;
        virtual int getCategoryFlags() const = 0;
        virtual std::string toString() const { return getName(); }

        inline bool isInCategory(E_Category category) {
            return getCategoryFlags() & category;
        }
    protected:
        bool m_Handled = false;
};

// Disaptcher for all events. 
class EventDispatcher {

    template<typename T>
    using eventFn = std::function<bool(T&)>;
    public: 
        EventDispatcher(Event& event)
                : m_Event{event} { }
        
        template<typename T>
        bool dispatch(eventFn<T> func) {
            if (m_Event.getEventType() == T::getStaticType()) {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
};

inline std::ostream& operator<<(std::ostream& os, const Event& e) {
    return os << e.toString();
}

}

#endif