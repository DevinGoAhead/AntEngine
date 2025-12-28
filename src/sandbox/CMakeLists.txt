add_executable(Sandbox SandboxApp.cpp)

target_link_libraries(Sandbox 
    PRIVATE    
        Ant
        SPDLOG
)

target_compile_definitions(Sandbox 
    PRIVATE
        ANT_BUILD
)