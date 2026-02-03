project(SANDBOX)

add_executable(sandbox SandboxApp.cpp)

target_link_libraries(sandbox 
    PRIVATE    
        ant
)

#ant_apply_options(sandbox)