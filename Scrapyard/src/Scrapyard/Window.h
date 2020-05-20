#ifndef WINDOW_H
#define WINDOW_H

#include <scypch.h>
#include <Core.h>
#include <Events/Event.h>

namespace Scrapyard {

    // Struct for storing basic window properties (such as height, width, title...etc)
    struct Properties {
        std::string title;
        unsigned int width;
        unsigned int height;

        Properties(const std::string title = "Scrapyard Engine", 
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : title{title}, width{width}, height{height} 
        { }
    };

    class Window {

        public:
            using EventCallbackFn = std::function<void(Event&)>;
            
            virtual ~Window() { }

            virtual void onUpdate() = 0;

            virtual unsigned int getWidth() const = 0;
            virtual unsigned int getHeight() const = 0;

            virtual void setEventCallback(const EventCallbackFn& callback) = 0;
            virtual void setVsync(bool enabled) = 0;
            virtual void isVsync() const = 0;

            static Window* Create(const Properties& probs = Properties());
    };
}

#endif