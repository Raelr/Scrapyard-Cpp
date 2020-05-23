#ifndef WINDOWS_WINDOW_H
#define WINDOWS_WINDOW_H

#include "Scrapyard/Window.h"

#include <GLFW/glfw3.h>

// Windows version of the window class - pretty much identical to the MacOSX version for now. 
namespace Scrapyard {
	class WindowsWindow : public Window
	{
    public:
        WindowsWindow(const Properties& props);
        virtual ~WindowsWindow();

        void onUpdate() override;

        virtual unsigned int getWidth() const override { return m_data.width; }
        virtual unsigned int getHeight() const override { return m_data.height; }

        inline void setEventCallback(const EventCallbackFn& callback) override { m_data.callback = callback; };
        virtual void setVsync(bool enabled) override;
        virtual bool isVsync() const override;
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
