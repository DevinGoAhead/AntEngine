add_library(ant
    SHARED 
        ant/Application.cpp
        ant/Log.cpp
        ant/Window.cpp
        ant/Layer.cpp
        ant/LayerStack.cpp

        ant/imgui/ImguiLayer.cpp

        platform/windows/WindowsWindow.cpp
        platform/windows/WindowsInput.cpp
        platform/opengl/OpenGLContext.cpp

        ${PROJECT_SOURCE_DIR}/include/ant/Input.hpp
)

target_include_directories(ant 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(ant 
    PUBLIC 
        glm::glm
        spdlog::spdlog
    PRIVATE
        OpenGL::GL
        glfw
        glad::glad
        imgui::imgui
)

target_compile_definitions(ant 
    PRIVATE
        ANT_BUILD
        IMGUI_API_EXPORT
)

ant_apply_options(ant)
ant_add_definitions(ant)