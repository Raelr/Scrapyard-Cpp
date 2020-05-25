#include "scypch.h"
#include "ProceduralMacWindow.h"

namespace Scrapyard {

    static bool s_GLFWInitialised = false;

    static void GLFWErrorCallback(int error, const char* description) {
        SCY_CORE_ERROR("GLFW Error: ({0}): {1}", error, description);
    }

    void test() {
        SCY_INFO("TEST");
    }

    MacWindow* initWindow(std::string title, int width, int height) {
        
        MacWindow* window = new MacWindow;
        WindowData data;

        data.title = title;
        data.width = width;
        data.height = height;

        window->data = data; 

        SCY_CORE_INFO("Creating Windows window {0} ({1}, {2})", data.title, data.width, data.height);

        if (!s_GLFWInitialised) {
            int success = glfwInit();
            SCY_ASSERT(success, "Failed to initialise GLFW!");
            s_GLFWInitialised = true;
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        window->window = glfwCreateWindow((int)data.width, (int)data.height, data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window->window);
        glfwSetWindowUserPointer(window->window, &window->data);

        //setVsync(true);
        return window;
    }

    void updateWindow(MacWindow* window) {
        glfwPollEvents();
        glfwSwapBuffers(window->window);
    }

    void destroyWindow(MacWindow* window) {
        glfwDestroyWindow(window->window);
    }

    void setVsync(MacWindow* window, bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        window->data.isVsync = enabled;
    }
}