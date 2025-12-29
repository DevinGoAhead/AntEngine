#include "ant/Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace AT{
    void Log::init(){
        spdlog::set_pattern("%^[%T] %n: %v%$");
        coreLogger = spdlog::stdout_color_mt("Ant");
        coreLogger->set_level(spdlog::level::level_enum::trace);
        clientLogger = spdlog::stdout_color_mt("App");
        clientLogger->set_level(spdlog::level::level_enum::trace);
    }
}