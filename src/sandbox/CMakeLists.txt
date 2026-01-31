add_executable(Sandbox SandboxApp.cpp)

target_link_libraries(Sandbox 
    PRIVATE    
        Ant
)

#ant_apply_options(Sandbox)