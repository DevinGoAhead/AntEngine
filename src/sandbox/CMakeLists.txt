add_executable(Sandbox SandboxApp.cpp)

target_link_libraries(Sandbox 
    PRIVATE    
        Ant
)

target_compile_definitions(Sandbox 
    PRIVATE
        ANT_STATIC
    PUBLIC
        $<$<CONFIG:Debug>:ANT_DEBUG>
        $<$<CONFIG:Release>:ANT_RELEASE>
)

#ant_apply_options(Sandbox)