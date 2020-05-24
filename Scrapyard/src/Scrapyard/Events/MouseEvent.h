#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "Event.h"

namespace Scrapyard {

    class MouseMovedEvent : public Event {
        
        public:
            MouseMovedEvent(float x, float y) 
                : m_mouseX{ x }, m_mouseY{ y } {}
            
            float getX() const { return m_mouseX; }
            float getY() const { return m_mouseY; }

            std::string toString() const override {
                std::stringstream ss;
                ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
                return ss.str();
            }

            E_CLASS_TYPE(MouseMoved)
            E_CLASS_CATEGORY(Mouse | Input)
        private:
            float m_mouseX, m_mouseY;
    };

    class MouseScrolledEvent : public Event {
        public: 
            MouseScrolledEvent(float xOffset, float yOffset) 
                    : m_xOffset(xOffset), m_yOffset(yOffset) { }
                        
            inline float getXOffset() const { return m_xOffset; }
            inline float getYOffset() const { return m_yOffset; }

            std::string toString() const override {
                std::stringstream ss;
                ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
                return ss.str();
            }

            E_CLASS_TYPE(MouseScroll)
            E_CLASS_CATEGORY(Mouse | Input)

        private: 
            float m_xOffset, m_yOffset;
    };

    class MouseButtonEvent : public Event {
        public:
            inline int getMouseButton() const { return m_Button; }

            E_CLASS_CATEGORY(Mouse | Input)
        protected:

            MouseButtonEvent(int button) 
                    : m_Button{button} { }

            int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
        public: 
            MouseButtonPressedEvent(int button)
                    : MouseButtonEvent(button) { }
            
            std::string toString() const override {
                std::stringstream ss;
                ss << "MouseButtonPressedEvent: " << m_Button;
                return ss.str();
            }

            E_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
        public:
            MouseButtonReleasedEvent(int button) 
                    : MouseButtonEvent(button) { }
            
            std::string toString() const override {
                std::stringstream ss;
                ss << "MouseButtonReleasedEvent: " << m_Button;
                return ss.str();
            }

            E_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif