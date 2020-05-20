#include "scypch.h"
#include "MacWindow.h"

namespace Scrapyard {

    static bool s_GLFWInitialised = false;

    Window* Window::Create(const Properties& props) {
        return new MacWindow(props);
    }

    MacWindow::MacWindow(const Properties& props) {
        init(props);
    }

    MacWindow::~MacWindow() {
        shutdown();
    }

    void MacWindow::init(const Properties& props) {
        
        // Transfer properties.
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;

        SCY_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

        if (!s_GLFWInitialised) {
            int success = glfwInit();
            SCY_ASSERT(success, "Failed to initialise GLFW!");
            s_GLFWInitialised = true;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        m_window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);

        setVsync(true);
    }

    void MacWindow::shutdown() {
        glfwDestroyWindow(m_window);
    }

    void MacWindow::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    void MacWindow::setVsync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        m_data.isVsync = enabled;
    }

    bool MacWindow::isVsync() const {
        return m_data.isVsync;
    }
}
