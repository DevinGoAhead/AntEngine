cmake_minimum_required(VERSION 3.26)
project(AntEngine VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D_DEBUG)
endif()


# ========================
#   Dependencies
# ========================

find_package(spdlog CONFIG REQUIRED)

add_library(SPDLOG INTERFACE)
target_link_libraries(SPDLOG INTERFACE spdlog::spdlog)

add_subdirectory(src/ant)
add_subdirectory(src/sandbox)
