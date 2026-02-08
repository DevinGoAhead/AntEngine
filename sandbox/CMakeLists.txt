project(SANDBOX)

add_executable(sandbox SandboxApp.cpp)

target_link_libraries(sandbox 
    PRIVATE    
        ant
)

target_compile_definitions(sandbox
    PRIVATE
        IMGUI_API_IMPORT
)

#ant_apply_options(sandbox)