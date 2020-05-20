#include "scypch.h"
#include "Application.h"
#include "Events/AppEvent.h"
#include "Log.h"

namespace Scrapyard {

    Application::Application() {
        m_window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {

    }

    void Application::run() {
        
        while(m_running) {
            m_window->onUpdate();
        }
    }

}