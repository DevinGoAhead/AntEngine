add_library(Ant
    SHARED 
        Application.cpp
        Log.cpp
        Window.cpp
        Layer.cpp
        LayerStack.cpp
        ${PROJECT_SOURCE_DIR}/src/platform/WindowsWindow.cpp
)

target_include_directories(Ant 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(Ant 
    PUBLIC 
        AntDeps
        AntGLFW
)

target_compile_definitions(Ant 
    PRIVATE
        ANT_BUILD
)

ant_apply_options(Ant)
ant_add_definitions(Ant)