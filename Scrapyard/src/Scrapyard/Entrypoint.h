#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include "Core.h"

#ifdef SCY_PLATFORM_MACOS

#include <spdlog/spdlog.h>

extern Scrapyard::Application* Scrapyard::CreateApplication();

int main(int argc, char** argv) {

    spdlog::info("Running Scrapyard with MacOSX build");
    auto* app = Scrapyard::CreateApplication();
    spdlog::info("Running Scrapyard...");
    app->run();
    spdlog::info("Closing Scrapyard");
    delete app;

    return 0;
}

#endif

#endif
