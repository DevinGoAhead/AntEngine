add_library(ant
    SHARED 
        ant/Application.cpp
        ant/Log.cpp
        ant/Window.cpp
        ant/Layer.cpp
        ant/LayerStack.cpp

        ant/imgui/ImguiLayer.cpp

        platform/WindowsWindow.cpp
        platform/WindowsInput.cpp

        ${PROJECT_SOURCE_DIR}/include/ant/Input.hpp
)

target_include_directories(ant 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(ant 
    PUBLIC 
        AntDeps
        AntGLFW
        AntGLAD
        AntIMGUI
)

target_compile_definitions(ant 
    PRIVATE
        ANT_BUILD
)

ant_apply_options(ant)
ant_add_definitions(ant)