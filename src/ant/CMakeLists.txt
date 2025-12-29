add_library(Ant SHARED Application.cpp Log.cpp Antpch.cpp )

target_include_directories(Ant 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(Ant 
    PRIVATE 
        SPDLOG)

target_compile_definitions(Ant 
    PRIVATE
        ANT_BUILD)