#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "Event.h"
#include <sstream>
#include <string>

namespace Scrapyard {

    class MouseMovedEvent : public Event {
        public:
            MouseMovedEvent(float x, float y) 
                    : m_MouseX{x}, m_MouseY{y} { }
            
            inline float getX const { return m_MouseX; }
            inline float getY const { return m_MouseY; }

            std::string toString() const override {
                std::stringstream ss;
                ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
                return ss.str();
            }

            E_CLASS_TYPE(MouseMoved)
            E_CLASS_CATEGORY(Mouse | Input)

        private:
            float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event {
        public: 
            MouseScrolledEvent(float xOffset, float yOffset) 
                    : m_XOffset(xOffset), m_YOffset(yOffset) { }
                        
            inline float getXOffset const { return m_XOffset; }
            inline float getYOffset const { return m_yOffset; }

            std::string toString() const override {
                std::stringstream ss;
                ss << "MouseScrolledEvent: " << getXOffset() << ", " << GetYOffset();
                return ss.str();
            }

            E_CLASS_TYPE(MouseScrolled)
            E_CLASS_CATEGORY(Mouse | Input)

        private: 
            float m_XOffset, m_yOffset;
    };

    class MouseButtonEvent : public Event {
        public:
            inline int GetMouseButton() const { return m_Button; }

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