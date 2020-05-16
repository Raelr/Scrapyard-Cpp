//
// Created by Aryeh Zinn on 11/5/20.
//

#ifndef VULKANPRACTICE_ENTRYPOINT_H
#define VULKANPRACTICE_ENTRYPOINT_H

#ifdef __APPLE__

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

#endif //VULKANPRACTICE_ENTRYPOINT_H
