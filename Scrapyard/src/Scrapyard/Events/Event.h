#ifndef EVENT_H
#define EVENT_H

#include "Scrapyard/Core.h"
#include <string>

namespace Scrapyard {

// Events are currently blocking - it is immediately dealt with once it is dispatched.

enum class EventType {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowFocusLost, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScroll
};

// Event Category -> bitmasks.
enum E_Category {
    None = 0,
    Application  = BIT(0),
    Input        = BIT(1),
    Keyboard     = BIT(2),
    Mouse        = BIT(3),
    MouseButton  = BIT(4)
};

class Event {
    
        friend class EventDispatcher;

    public:
        virtual EventType getEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(E_Category category) {
            return GetCategoryFlags() & category;
        }
    protected:
        bool m_handled = false;
};

}

#endif