#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "Event.h"

#include <sstream>

namespace Scrapyard {

    class KeyEvent {
        public: 
            inline int getKeyCode() const {return m_keyCode; }
            E_CLASS_CATEGORY(Keyboard | Input)
        protected:
            KeyEvent(int keyCode) 
                    : m_keyCode{keyCode} { }
            int m_keyCode;
    };

    class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(int keyCode, int repeatCount) 
                    : KeyEvent(keyCode), m_repeatCount{repeatCount} { }
            
            inline int getRepeatCount() const { return m_repeatCount; }

            std::string toString const override {
                std::stringstream ss; 
                ss << "KeyPressedEvent: " << m_keyCode << " ( " << m_repeatCount << " repeats)";
                return ss.str();
            }
            E_CLASS_TYPE(KeyPressed)
        private:
            int m_repeatCount;

    };

    class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(int keyCode) 
                    : KeyEvent(keyCode) { }
            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyReleasedEvent: " << m_keyCode;
                return ss.str();
            }

            E_CLASS_TYPE(KeyReleased)
    };
}



#endif