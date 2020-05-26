#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include "Core.h"
#include "Platform/Macosx/ProceduralMacWindow.h"

#ifdef SCY_PLATFORM_MACOS

extern Scrapyard::Application* Scrapyard::CreateApplication();

int main(int argc, char** argv) {

    Scrapyard::Log::init();

    SCY_CORE_TRACE("Starting Scrapyard...");
    
    auto* app = Scrapyard::CreateApplication();

    // auto* window = Scrapyard::initWindow();
    
    SCY_CORE_INFO("Running Scrapyard...");

    // while (Scrapyard::isActive(window->data)) {
    // Scrapyard::updateWindow(window->window);
    // }
    app->run();

    SCY_INFO("Shutting Scrapyard down!");
    
    // Scrapyard::destroyWindow(window);
    // delete window;
    delete app;

    return 0;
}

#endif

#ifdef SCY_PLATFORM_WINDOWS

extern Scrapyard::Application* Scrapyard::CreateApplication();

int main(int argc, char** argv) {

    Scrapyard::Log::init();

    SCY_CORE_TRACE("Starting Scrapyard...");

    auto* app = Scrapyard::CreateApplication();

    SCY_CORE_INFO("Running Scrapyard...");

    app->run();

    SCY_INFO("Shutting Scrapyard down!");

    delete app;

    return 0;
}

#endif
#endif