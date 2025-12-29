#pragma once

#include "Antpch.h"

#include <spdlog/spdlog.h>

#include <memory>

namespace AT {
class ANT_API Log {
   public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
        return coreLogger;
    }

    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
        return clientLogger;
    }

   private:
    inline static std::shared_ptr<spdlog::logger> coreLogger;
    inline static std::shared_ptr<spdlog::logger> clientLogger;
};
}  // namespace AT

#ifdef _DEBUG

#define ANT_CORE_TRACE(...)            \
    ::AT::Log::GetCoreLogger()->trace( \
        __VA_ARGS__) /* ::AT 直接在全局命名空间查找 */
#define ANT_CORE_DEBUG(...) ::AT::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define ANT_CORE_INFO(...) ::AT::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ANT_CORE_WARN(...) ::AT::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ANT_CORE_ERROR(...) ::AT::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ANT_CORE_CRITICAL(...) ::AT::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define ANT_TRACE(...)                   \
    ::AT::Log::GetClientLogger()->trace( \
        __VA_ARGS__) /* ::AT 直接在全局命名空间查找 */
#define ANT_DEBUG(...) ::AT::Log::GetClientLogger()->debug(__VA_ARGS__)
#define ANT_INFO(...) ::AT::Log::GetClientLogger()->info(__VA_ARGS__)
#define ANT_WARN(...) ::AT::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ANT_ERROR(...) ::AT::Log::GetClientLogger()->error(__VA_ARGS__)
#define ANT_CRITICAL(...) ::AT::Log::GetClientLogger()->critical(__VA_ARGS__)

#elif

#define ANT_CORE_TRACE(...)
#define ANT_CORE_DEBUG(...)
#define ANT_CORE_INFO(...)
#define ANT_CORE_WARN(...)
#define ANT_CORE_ERROR(...)
#define ANT_CORE_CRITICAL(...)

#define ANT_TRACE(...)
#define ANT_DEBUG(...)
#define ANT_INFO(...)
#define ANT_WARN(...)
#define ANT_ERROR(...)
#define ANT_CRITICAL(...)

#endif