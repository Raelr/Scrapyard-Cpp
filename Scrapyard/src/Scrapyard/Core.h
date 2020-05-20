#ifndef CORE_H
#define CORE_H

    #if defined(__APPLE__) || defined(__MACH__)
        #define SCY_PLATFORM_MACOS
    #elif defined(WIN32) || defined(_WIN32) || defined(__WIN32)
        #if defined(WIN64) || defined(_WIN64)
            #define SCY_PLATFORM_WINDOWS
    #endif
    #endif

#endif

#define BIT(x) (1 << x)