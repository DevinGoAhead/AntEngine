add_library(glad glad.c)

# 父项目用 glad::glad 链接
add_library(glad::glad ALIAS glad)

target_include_directories(glad PUBLIC
    "$<BUILD_INTERFACE:${GLAD_SOURCE_DIR}/include>"
)

