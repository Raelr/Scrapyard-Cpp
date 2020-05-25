#ifndef PROCEDURAL_MAC_WINDOW_H
#define PROCEDURAL_MAC_WINDOW_H

#include <GLFW/glfw3.h>

namespace Scrapyard {
    void test();

    struct WindowData {

        std::string title;

        unsigned int width, height;
        bool isVsync;

        using EventCallbackFn = std::function<void()>;
    };

    struct MacWindow {
        WindowData data;
        GLFWwindow* window;
    };

    MacWindow* initWindow(std::string title = "Scrapyard Engine", int width = 1280, int height = 720);

    void updateWindow(MacWindow*);

    void destroyWindow(MacWindow*);
}

#endif