#pragma once

#include "ant/Core.h"

#include "spdlog/fmt/fmt.h"  // IWYU pragma: keep
//#include "spdlog/spdlog.h"  // IWYU pragma: keep

#include <memory>

namespace spdlog {
class logger;
}

namespace AE {
class ANT_API Log {
   public:
    enum class LogLevel : std::int8_t {
        Trace,
        Debug,
        Info,
        Warn,
        Error,
        Critical
    };

   public:
    static void init();

    template <typename... Args>
    static void LogCore(LogLevel level, fmt::format_string<Args...> fmtString,
                          Args&&... args) {
        return LogCoreImpl(level,
                           fmt::format(fmtString, std::forward<Args>(args)...));
    }

    template <typename... Args>
    static void LogClient(LogLevel level, fmt::format_string<Args...> fmtString,
                            Args&&... args) {
        return LogClientImpl(
            level, fmt::format(fmtString, std::forward<Args>(args)...));
    }

    // static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
    //     //coreLogger->error()
    //     return coreLogger;
    // }

    // static std::shared_ptr<spdlog::logger>& GetClientLogger() {
    //     return clientLogger;
    // }

   private:
    static void LogCoreImpl(LogLevel level, std::string_view message);
    static void LogClientImpl(LogLevel level, std::string_view message);

   private:
    inline static std::shared_ptr<spdlog::logger> coreLogger;
    inline static std::shared_ptr<spdlog::logger> clientLogger;
};
}  // namespace AE

// #if defined ANT_ENABLE_LOG

// #define ANT_LOG_CORE_TRACE(...)        \
//     ::AE::Log::GetCoreLogger()->trace( \
//         __VA_ARGS__) /* ::AE 直接在全局命名空间查找 */
// #define ANT_LOG_CORE_DEBUG(...) ::AE::Log::GetCoreLogger()->debug(__VA_ARGS__)
// #define ANT_LOG_CORE_INFO(...) ::AE::Log::GetCoreLogger()->info(__VA_ARGS__)
// #define ANT_LOG_CORE_WARN(...) ::AE::Log::GetCoreLogger()->warn(__VA_ARGS__)
// #define ANT_LOG_CORE_ERROR(...) ::AE::Log::GetCoreLogger()->error(__VA_ARGS__)
// #define ANT_LOG_CORE_CRITICAL(...) \
//     ::AE::Log::GetCoreLogger()->critical(__VA_ARGS__)

// #define ANT_LOG_TRACE(...)               \
//     ::AE::Log::GetClientLogger()->trace( \
//         __VA_ARGS__) /* ::AE 直接在全局命名空间查找 */
// #define ANT_LOG_DEBUG(...) ::AE::Log::GetClientLogger()->debug(__VA_ARGS__)
// #define ANT_LOG_INFO(...) ::AE::Log::GetClientLogger()->info(__VA_ARGS__)
// #define ANT_LOG_WARN(...) ::AE::Log::GetClientLogger()->warn(__VA_ARGS__)
// #define ANT_LOG_ERROR(...) ::E::Log::GetClientLogger()->error(__VA_ARGS__)
// #define ANT_LOG_CRITICAL(...) \
//     ::AE::Log::GetClientLogger()->critical(__VA_ARGS__)

// #else

#if defined ANT_ENABLE_LOG

#define ANT_LOG_CORE_TRACE(...) \
    ::AE::Log::LogCore(::AE::Log::LogLevel::Trace, __VA_ARGS__) /* ::AE 直接在全局命名空间查找 */
#define ANT_LOG_CORE_DEBUG(...) ::AE::Log::LogCore(::AE::Log::LogLevel::Debug, __VA_ARGS__)
#define ANT_LOG_CORE_INFO(...) ::AE::Log::LogCore(::AE::Log::LogLevel::Info, __VA_ARGS__)
#define ANT_LOG_CORE_WARN(...) ::AE::Log::LogCore(::AE::Log::LogLevel::Warn, __VA_ARGS__)
#define ANT_LOG_CORE_ERROR(...) ::AE::Log::LogCore(::AE::Log::LogLevel::Error, __VA_ARGS__)
#define ANT_LOG_CORE_CRITICAL(...) ::AE::Log::LogCore(::AE::Log::LogLevel::Critial, __VA_ARGS__)

#define ANT_LOG_TRACE(...) \
    ::AE::Log::LogClient(::AE::Log::LogLevel::Trace, __VA_ARGS__) /* ::AE 直接在全局命名空间查找 */
#define ANT_LOG_DEBUG(...) ::AE::Log::LogClient(::AE::Log::LogLevel::Debug, __VA_ARGS__)
#define ANT_LOG_INFO(...) ::AE::Log::LogClient(::AE::Log::LogLevel::Info, __VA_ARGS__)
#define ANT_LOG_WARN(...) ::AE::Log::LogClient(::AE::Log::LogLevel::Warn, __VA_ARGS__)
#define ANT_LOG_ERROR(...) ::AE::Log::LogClient(::AE::Log::LogLevel::Error, __VA_ARGS__)
#define ANT_LOG_CRITICAL(...) ::AE::Log::LogClient(::AE::Log::LogLevel::Critial, __VA_ARGS__)

#else

#define ANT_LOG_CORE_TRACE(...)
#define ANT_LOG_CORE_DEBUG(...)
#define ANT_LOG_CORE_INFO(...)
#define ANT_LOG_CORE_WARN(...)
#define ANT_LOG_CORE_ERROR(...)
#define ANT_LOG_CORE_CRITICAL(...)

#define ANT_LOG_TRACE(...)
#define ANT_LOG_DEBUG(...)
#define ANT_LOG_INFO(...)
#define ANT_LOG_WARN(...)
#define ANT_LOG_ERROR(...)
#define ANT_LOG_CRITICAL(...)

#endif