#ifndef MACWINDOW_H
#define MACWINDOW_H

#include <Scrapyard/Window.h>

#include <GLFW/glfw3.h>

namespace Scrapyard {

    class MacWindow : public Window {
        public:
            MacWindow(const Properties& props);
            virtual ~MacWindow();

            void onUpdate() override;

            virtual unsigned int getWidth() const override { return m_data.width; }
            virtual unsigned int getHeight() const override { return m_data.height; }

            inline void setEventCallback(const EventCallbackFn& callback) override { m_data.callback = callback; };
            virtual void setVsync(bool enabled) override;
            virtual void isVsync() const override;
        private:

            virtual void init(const Properties& props);
            virtual void shutdown();

            GLFWwindow* m_window;

            struct Data {

                std::string title;
                unsigned int width, height;
                bool isVsync;

                EventCallbackFn callback;
            };

            Data m_data;
    };

}

#endif