add_library(Ant SHARED Application.cpp Log.cpp)

target_include_directories(Ant 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(Ant 
    PRIVATE 
        AntDeps)

target_compile_definitions(Ant 
    PRIVATE
        ANT_BUIL
    PUBLIC
        $<$<CONFIG:Debug>:ANT_DEBUG>
        $<$<CONFIG:Release>:ANT_RELEASE>
)

ant_apply_options(Ant)
ant_add_definitions(Ant)