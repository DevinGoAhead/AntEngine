add_library(Platform WindowWindow.cpp)

target_include_directories(Platform 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(Platform 
    PRIVATE 
        AntDeps
        AntGLFW
)

target_compile_definitions(Platform 
    PRIVATE
        ANT_STATIC
    PUBLIC
        $<$<CONFIG:Debug>:ANT_DEBUG>
        $<$<CONFIG:Release>:ANT_RELEASE>
)

ant_apply_options(Platform)
ant_add_definitions(Platform)