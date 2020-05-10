//
// Created by Aryeh Zinn on 11/5/20.
//

#ifndef VULKANPRACTICE_ENTRYPOINT_H
#define VULKANPRACTICE_ENTRYPOINT_H

#ifdef __APPLE__

extern Scrapyard::Application* Scrapyard::CreateApplication();

int main(int argc, char** argv) {

    printf("DETECTING APPLE MACHINE\n");
    auto* app = Scrapyard::CreateApplication();
    app->run();
    delete app;

    return 0;
}

#endif

#endif //VULKANPRACTICE_ENTRYPOINT_H
