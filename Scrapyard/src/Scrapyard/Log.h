#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Scrapyard {

    class Log {

        public:
            static void init();
            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
        private:
            static std::shared_ptr<spdlog::logger> s_CoreLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core logging macros

#define SCY_CORE_TRACE(...) ::Scrapyard::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SCY_CORE_INFO(...)  ::Scrapyard::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SCY_CORE_WARN(...)  ::Scrapyard::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SCY_CORE_ERROR(...) ::Scrapyard::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SCY_CORE_FATAL(...) ::Scrapyard::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logging macros

#define SCY_TRACE(...) ::Scrapyard::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SCY_INFO(...)  ::Scrapyard::Log::GetClientLogger()->info(__VA_ARGS__)
#define SCY_WARN(...)  ::Scrapyard::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SCY_ERROR(...) ::Scrapyard::Log::GetClientLogger()->error(__VA_ARGS__)
#define SCY_FATAL(...) ::Scrapyard::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif