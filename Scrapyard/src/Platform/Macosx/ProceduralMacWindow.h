/*
    NOTE: This is a test class to see how you could achieve a window through a procedural
    interface. The goal will be to try and learn how these features could be built using
    both OOP and procedural. 
*/

#ifndef PROCEDURAL_MAC_WINDOW_H
#define PROCEDURAL_MAC_WINDOW_H

#include <GLFW/glfw3.h>

namespace Scrapyard {
    void test();

    struct WindowData {

        std::string title;

        unsigned int width, height;
        
        bool isVsync;

        bool isActive;
    };

    struct MacWindow {
        WindowData data;
        GLFWwindow* window;
        MacWindow(WindowData data, GLFWwindow* window) 
                : data{data}, window{window} 
        { }
    };

    MacWindow* initWindow(std::string title = "Scrapyard Engine", int width = 1280, int height = 720);

    void updateWindow(GLFWwindow*);

    void destroyWindow(MacWindow*);

    void setVsync(MacWindow*, bool);

    bool isActive(MacWindow* window);
}

#endif