#include "scypch.h"
#include "Application.h"
#include "Events/AppEvent.h"
#include "Log.h"

namespace Scrapyard {

    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::run() {
        WindowResizeEvent e(1920, 1080);
        SCY_TRACE(e);
    }

}