#include "scypch.h"
#include "Application.h"
#include "Events/AppEvent.h"
#include "Log.h"

namespace Scrapyard {

    // Macro for binding events - makes it easier to reduce boilderplate code. 
    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application() {
        m_window = std::unique_ptr<Window>(Window::Create());
        m_window->setEventCallback(BIND_EVENT_FN(onEvent));
    }

    Application::~Application() {

    }

    void Application::onEvent(Event& e) {

        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
        SCY_CORE_TRACE("{0}", e);
    }

    void Application::run() {
        
        while(m_running) {
            m_window->onUpdate();
        }
    }

    bool Application::onWindowClose(WindowCloseEvent& e) {
        m_running = false;
        return true;
    }

}