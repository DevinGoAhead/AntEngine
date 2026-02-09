#include "ant/Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace AE {
void Log::init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    coreLogger = spdlog::stdout_color_mt("Ant");
    coreLogger->set_level(spdlog::level::level_enum::trace);

    clientLogger = spdlog::stdout_color_mt("App");
    clientLogger->set_level(spdlog::level::level_enum::trace);
}

// void Log::LogCoreImpl(LogLevel level, std::string_view message) {
//     switch (level) {
//         case LogLevel::Trace:
//             coreLogger->trace(message);
//             break;
//         case LogLevel::Debug:
//             coreLogger->debug(message);
//             break;
//         case LogLevel::Info:
//             coreLogger->info(message);
//             break;
//         case LogLevel::Warn:
//             coreLogger->warn(message);
//             break;
//         case LogLevel::Error:
//             coreLogger->error(message);
//             break;
//         case LogLevel::Critical:
//             coreLogger->critical(message);
//             break;
//     }
// }

// void Log::LogClientImpl(LogLevel level, std::string_view message) {
//     switch (level) {
//         case LogLevel::Trace:
//              clientLogger->trace(message);
//              break;
//         case LogLevel::Debug:
//              clientLogger->debug(message);
//              break;
//         case LogLevel::Info:
//              clientLogger->info(message);
//              break;
//         case LogLevel::Warn:
//              clientLogger->warn(message);
//              break;
//         case LogLevel::Error:
//              clientLogger->error(message);
//              break;
//         case LogLevel::Critical:
//              clientLogger->critical(message);
//              break;
//     }
// }
}  // namespace AE