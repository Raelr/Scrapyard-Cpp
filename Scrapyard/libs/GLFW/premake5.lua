
project "GLFW"
location "GLFW"
kind "StaticLib"
language "C"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

files
{
    "%{prj.name}/include/GLFW/glfw3.h",
    "%{prj.name}/include/GLFW/glfw3native.h",
    "%{prj.name}/src/glfw_config.h",
    "%{prj.name}/src/context.c",
    "%{prj.name}/src/init.c",
    "%{prj.name}/src/input.c",
    "%{prj.name}/src/monitor.c",
    "%{prj.name}/src/vulkan.c",
    "%{prj.name}/src/window.c"
}

filter "system:linux"
    pic "On"

    systemversion "latest"
    staticruntime "On"

    files
    {
        "%{prj.name}/src/x11_init.c",
        "%{prj.name}/src/x11_monitor.c",
        "%{prj.name}/src/x11_window.c",
        "%{prj.name}/src/xkb_unicode.c",
        "%{prj.name}/src/posix_time.c",
        "%{prj.name}/src/posix_thread.c",
        "%{prj.name}/src/glx_context.c",
        "%{prj.name}/src/egl_context.c",
        "%{prj.name}/src/osmesa_context.c",
        "%{prj.name}/src/linux_joystick.c"
    }

    defines
    {
        "_GLFW_X11"
    }

filter "system:windows"
    systemversion "latest"
    staticruntime "On"

    files
    {
        "%{prj.name}/src/win32_init.c",
        "%{prj.name}/src/win32_joystick.c",
        "%{prj.name}/src/win32_monitor.c",
        "%{prj.name}/src/win32_time.c",
        "%{prj.name}/src/win32_thread.c",
        "%{prj.name}/src/win32_window.c",
        "%{prj.name}/src/wgl_context.c",
        "%{prj.name}/src/egl_context.c",
        "%{prj.name}/src/osmesa_context.c"
    }

    defines 
    { 
        "_GLFW_WIN32",
        "_CRT_SECURE_NO_WARNINGS"
    }

filter "system:macosx"
    systemversion "latest"
    staticruntime "On"
    
    files {
        "%{prj.name}/src/cocoa_init.m",
        "%{prj.name}/src/cocoa_joystick.m",
        "%{prj.name}/src/cocoa_monitor.m",
        "%{prj.name}/src/cocoa_time.c",
        "%{prj.name}/src/posix_thread.c",
        "%{prj.name}/src/cocoa_window.m",
        "%{prj.name}/src/egl_context.c",
        "%{prj.name}/src/nsgl_context.m",
        "%{prj.name}/src/osmesa_context.c"
    }

    defines {
    "_GLFW_COCOA"
    }

filter "configurations:Debug"
    runtime "Debug"
    symbols "on"

filter "configurations:Release"
    runtime "Release"
    optimize "on"