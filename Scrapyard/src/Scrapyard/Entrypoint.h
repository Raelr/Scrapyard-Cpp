#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include "Core.h"

#ifdef SCY_PLATFORM_MACOS

extern Scrapyard::Application* Scrapyard::CreateApplication();

int main(int argc, char** argv) {

    Scrapyard::Log::init();
    Scrapyard::Log::GetCoreLogger()->warn("Initialised log!");
    Scrapyard::Log::GetClientLogger()->info("Hello!");

    auto* app = Scrapyard::CreateApplication();
    app->run();
    delete app;

    return 0;
}

#endif

#endif
