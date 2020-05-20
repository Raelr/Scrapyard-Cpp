#ifndef CORE_H
#define CORE_H

    #if defined(__APPLE__) || defined(__MACH__)
        #define SCY_PLATFORM_MACOS
    #elif defined(WIN32) || defined(_WIN32) || defined(__WIN32)
        #if defined(WIN64) || defined(_WIN64)
            #define SCY_PLATFORM_WINDOWS
    #endif
    #endif

    #ifdef SCY_ENABLE_ASSERTS
        #define SCY_ASSERT(x, ...) { if(!(x)) { SCY_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
        #define SCY_CORE_ASSERT(x, ...) { if(!(x)) { SCY_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #else
        #define SCY_ASSERT(x, ...)
        #define SCY_CORE_ASSERT(x, ...)
    #endif

    #define BIT(x) (1 << x)

#endif

