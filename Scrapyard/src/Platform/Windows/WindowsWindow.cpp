#include "scypch.h"
#include "WindowsWindow.h"

// Event includes
#include "Scrapyard/Events/AppEvent.h"
#include "Scrapyard/Events/KeyEvent.h"

namespace Scrapyard {

    static bool s_GLFWInitialised = false;

    Window* Window::Create(const Properties& props) {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const Properties& props) {
        init(props);
    }

    WindowsWindow::~WindowsWindow() {
        shutdown();
    }

    void WindowsWindow::init(const Properties& props) {

        // Transfer properties.
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;

        SCY_CORE_INFO("Creating Windows window {0} ({1}, {2})", props.title, props.width, props.height);

        if (!s_GLFWInitialised) {
            int success = glfwInit();
            SCY_ASSERT(success, "Failed to initialise GLFW!");
            s_GLFWInitialised = true;
        }

        m_window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);

        setVsync(true);

        // GLFW Event Callbacks

        // Window Resize event. 
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
            
            Data& data = *(Data*)glfwGetWindowUserPointer(window);

            data.height = height;
            data.width = width;

            WindowResizeEvent event(width, height);
            data.callback(event);
        });

        // Window Close event.
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
            
            Data& data = *(Data*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data.callback(event);
        });


    }

    void WindowsWindow::shutdown() {
        glfwDestroyWindow(m_window);
    }

    void WindowsWindow::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    void WindowsWindow::setVsync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        }
        else {
            glfwSwapInterval(0);
        }
        m_data.isVsync = enabled;
    }

    bool WindowsWindow::isVsync() const {
        return m_data.isVsync;
    }
}