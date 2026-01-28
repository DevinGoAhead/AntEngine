#pragma once

#include "ant/Core.h"

#include <spdlog/spdlog.h>

#include <memory>

namespace AE {
class ANT_API Log {
   public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
        //coreLogger->error()
        return coreLogger;
    }

    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
        return clientLogger;
    }

   private:
    inline static std::shared_ptr<spdlog::logger> coreLogger;
    inline static std::shared_ptr<spdlog::logger> clientLogger;
};
}  // namespace AE


#if defined ANT_ENABLE_LOG

#define ANT_LOG_CORE_TRACE(...)            \
    ::AE::Log::GetCoreLogger()->trace( \
        __VA_ARGS__) /* ::AE 直接在全局命名空间查找 */
#define ANT_LOG_CORE_DEBUG(...) ::AE::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define ANT_LOG_CORE_INFO(...) ::AE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ANT_LOG_CORE_WARN(...) ::AE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ANT_LOG_CORE_ERROR(...) ::AE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ANT_LOG_CORE_CRITICAL(...) ::AE::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define ANT_TRACE(...)                   \
    ::AE::Log::GetClientLogger()->trace( \
        __VA_ARGS__) /* ::AE 直接在全局命名空间查找 */
#define ANT_LOG_DEBUG(...) ::AE::Log::GetClientLogger()->debug(__VA_ARGS__)
#define ANT_LOG_INFO(...) ::AE::Log::GetClientLogger()->info(__VA_ARGS__)
#define ANT_LOG_WARN(...) ::AE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ANT_LOG_ERROR(...) ::E::Log::GetClientLogger()->error(__VA_ARGS__)
#define ANT_LOG_CRITICAL(...) ::AE::Log::GetClientLogger()->critical(__VA_ARGS__)

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