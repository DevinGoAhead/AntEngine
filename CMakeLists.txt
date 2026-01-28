cmake_minimum_required(VERSION 3.26)
project(AntEngine VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/") # 可执行程序
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/") # shared lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/$<CONFIG>-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/") # static lib + win 动态库配套的 import lib

option(ANT_WARNINGS "Enable common compiler warnings" ON)
option(ANT_WERROR "Treat warnings as errors" OFF)
set(ANT_SANITIZE "OFF" CACHE STRING "Sanitizers: OFF or comma list (address,undefined,thread,leak)")
option(ANT_LTO "Enable Link Time Optimization" OFF)
option(ANT_DIST "Enable distribution mode" OFF)


function(ant_apply_options target_name)
  if(ANT_WARNINGS)
    if(MSVC)
      target_compile_options(${target_name} PRIVATE /W4)
    else()
      target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
  endif()

  if(ANT_WERROR)
    if(MSVC)
      target_compile_options(${target_name} PRIVATE /WX)
    else()
      target_compile_options(${target_name} PRIVATE -Werror)
    endif()
  endif()

  # Sanitizers（只对 clang/gcc）
  if(NOT ANT_SANITIZE STREQUAL "OFF")
    if(MSVC)
      message(WARNING "Sanitizers via ANT_SANITIZE are not enabled for MSVC in this template.")
    else()
      # 允许 ANT_SANITIZE="address,undefined"
      # list: 本质是 ; 分隔的字符串
      string(REPLACE "," ";" _san_list "${ANT_SANITIZE}")
      string(JOIN "," _san_csv ${_san_list})

      target_compile_options(${target_name} PRIVATE -fsanitize=${_san_csv} -fno-omit-frame-pointer)
      target_link_options(${target_name} PRIVATE -fsanitize=${_san_csv})
    endif()
  endif()

  # LTO（跨平台方式：CMake 原生）
  if(ANT_LTO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT _ipo_ok OUTPUT _ipo_msg)
    if(_ipo_ok)
      set_property(TARGET ${target_name} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
      message(WARNING "IPO/LTO not supported: ${_ipo_msg}")
    endif()
  endif()
endfunction()


option(ANT_LOGGING "Enable logging macros" OFF)
option(ANT_ASSERTING "Enable assert macros" OFF)

function(ant_add_definitions target_name)
  # 是否启用日志打印
  if(ANT_LOGGING)
    target_compile_definitions(${target_name} PUBLIC ANT_ENABLE_LOG)
  else()
    message(WARNING "ANT_LOGGING: ${ANT_LOGGING}")
  endif()
  if(ANT_ASSERTING)
    target_compile_definitions(${target_name} PUBLIC ANT_ENABLE_ASSERT)
  else()
    message(WARNING "ANT_ASSERTING: ${ANT_ASSERTING}")
  endif()
endfunction()

# GLFW 配置
## 创建一些 CACHE(全局) 变量, 子 cmake 也可以读到
# set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs" FORCE)
# set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" FORCE)
# set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation" FORCE)
### 我自己的机器是 wayland, 所以我关掉了 x11
# set(GLFW_BUILD_X11 OFF CACHE BOOL "Build support for X11" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")

add_subdirectory(src/ant)
add_subdirectory(src/sandbox)
add_subdirectory(src/platform)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)


# spdlog
# target - spdlog::spdlog 的 POSITION_INDEPENDENT_CODE 打开, 静态库编译启用位置无关码
set_target_properties(spdlog PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Dependencies


# 使用比较普遍的都可以 link 到 AntDeps
add_library(AntDeps INTERFACE)

find_package(OpenGL REQUIRED)
target_link_libraries(AntDeps
  INTERFACE
    spdlog::spdlog
    OpenGL::GL
)

add_library(AntGLFW INTERFACE)
target_link_libraries(AntGLFW
  INTERFACE
    glfw
)

