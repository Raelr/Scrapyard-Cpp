#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include <spdlog/spdlog.h>
#include <memory>

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

#endif