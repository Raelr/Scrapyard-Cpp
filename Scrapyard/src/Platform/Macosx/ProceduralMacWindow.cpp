/*
    NOTE: This is a test class to see how you could achieve a window through a procedural
    interface. The goal will be to try and learn how these features could be built using
    both OOP and procedural. 
*/

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
        
        WindowData data;

        data.title = title;
        data.width = width;
        data.height = height;

        SCY_CORE_INFO("Creating Windows window {0} ({1}, {2})", data.title, data.width, data.height);

        if (!s_GLFWInitialised) {
            int success = glfwInit();
            SCY_ASSERT(success, "Failed to initialise GLFW!");
            s_GLFWInitialised = true;
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        GLFWwindow* win = glfwCreateWindow((int)data.width, (int)data.height, data.title.c_str(), nullptr, nullptr);
        
        MacWindow* window = new MacWindow(data, win);
        
        glfwSetWindowUserPointer(win, &window->data);

        // Window Close event.
        glfwSetWindowCloseCallback(win, [](GLFWwindow* window) {
            
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            SCY_CORE_INFO("CLOSING SCRAPYARD...");

            data.isActive = false;
        });

        return window;
    }

    void updateWindow(GLFWwindow* window) {
        glfwPollEvents();
    }

    void destroyWindow(MacWindow* window) {
        glfwDestroyWindow(window->window);
    }

    bool isActive(WindowData data) {
        return data.isActive;
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