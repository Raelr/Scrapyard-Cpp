#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "Event.h"
#include <sstream>
#include <string>

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
}

#endif