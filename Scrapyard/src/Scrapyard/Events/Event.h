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
#define E_CLASS_TYPE(type)  static EventType getstaticType() {return EventType::##type; } \
                            virtual EventType getEventType() const override { return GetStaticType(); } \
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
        bool m_handled = false;
};



class EventDispatcher {



};

}

#endif