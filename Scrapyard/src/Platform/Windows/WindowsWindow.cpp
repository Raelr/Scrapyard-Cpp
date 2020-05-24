#include "scypch.h"
#include "WindowsWindow.h"

// Event includes
#include "Scrapyard/Events/AppEvent.h"
#include "Scrapyard/Events/KeyEvent.h"
#include "Scrapyard/Events/MouseEvent.h"

namespace Scrapyard {

    static bool s_GLFWInitialised = false;

    Window* Window::Create(const Properties& props) {
        return new WindowsWindow(props);
    }

    static void GLFWErrorCallback(int error, const char* description) {
        SCY_CORE_ERROR("GLFW Error: ({0}): {1}", error, description);
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
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        m_window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);

        setVsync(true);

        // ---------------- GLFW Event Callbacks --------------------------------------------------------------

        // Window Resize event. 
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
            
            Data& data = *(Data*)glfwGetWindowUserPointer(window);

            data.height = height;
            data.width = width;

            WindowResizeEvent event(width, height);
            // Calls onEvent() in application (since it was bound in application constructor)
            data.callback(event);
        });

        // Window Close event.
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
            
            Data& data = *(Data*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            // Calls onEvent() in application (since it was bound in application constructor)
            data.callback(event);
        });

        // Set Key Callbacks for GLFW
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            
            Data& data = *(Data*)glfwGetWindowUserPointer(window);
            
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    // Calls onEvent() in application (since it was bound in application constructor)
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    // Calls onEvent() in application (since it was bound in application constructor)
                    data.callback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    // Calls onEvent() in application (since it was bound in application constructor)
                    data.callback(event);
                    break;
                }
            }
        });

        // Mouse Button Events
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
            
            Data& data = *(Data*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    // Calls onEvent() in application (since it was bound in application constructor)
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    // Calls onEvent() in application (since it was bound in application constructor)
                    data.callback(event);
                    break;
                }
            }
        });

        // Mouse Scroll event
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {

            Data& data = *(Data*)glfwGetWindowUserPointer(window);
            
            MouseScrolledEvent event(xOffset, yOffset);
            // Calls onEvent() in application (since it was bound in application constructor)
            data.callback(event);
        });

        // Mouse position Callback
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos) {
            Data& data = *(Data*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event(xPos, yPos);
            // Calls onEvent() in application (since it was bound in application constructor)
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