#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "scypch.h"
#include "Window.h"

namespace Scrapyard {

    class Application {

    public:
        Application();
        ~Application();
        void run();
    private:
        std::unique_ptr<Window> m_window;
        bool m_running = true;
    };

    // To be defined in CLIENT.
    Application* CreateApplication();
}




#endif
