#ifndef APPEVENT_H
#define APPEVENT_H

#include "Event.h"
#include <sstream>
#include <string>

namespace Scrapyard {

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) 
                : m_Width{width}, m_Height{height} {}
        
        inline unsigned int getWidth() { return m_Width; }
        inline unsigned int getHeight() { return m_Height; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "Window resized: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        E_CLASS_TYPE(WindowResize)
        E_CLASS_CATEGORY(Application)
    private:
        unsigned int m_Width, m_Height;
    };

    class WindowCloseEvent : public Event {
        public:
            WindowCloseEvent() { }
            
            E_CLASS_TYPE(WindowClose)
            E_CLASS_CATEGORY(Application)

    };

    class TickEvent : public Event {
        public: 
            TickEvent() { }

            E_CLASS_TYPE(AppTick)
            E_CLASS_CATEGORY(Application)
    };

    class UpdateEvent : public Event {
        public: 
            UpdateEvent() { }

            E_CLASS_TYPE(AppUpdate)
            E_CLASS_CATEGORY(Application)
    };

    class RenderEvent : public Event {
        public: 
            RenderEvent() { }

            E_CLASS_TYPE(AppRender)
            E_CLASS_CATEGORY(Application)
    };
}



#endif