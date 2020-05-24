#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "scypch.h"
#include "Events/Event.h"
#include "Events/AppEvent.h"
#include "Window.h"

namespace Scrapyard {

    class Application {

    public:
        Application();
        ~Application();
        void run();
        void onEvent(Event& e);
    private:
        bool onWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_window;
        bool m_running = true;
    };

    // To be defined in CLIENT.
    Application* CreateApplication();
}

#endif
