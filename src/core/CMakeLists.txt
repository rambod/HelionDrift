cmake_minimum_required(VERSION 4.1)
add_library(helion_core STATIC
        core.cpp
)

target_include_directories(helion_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(helion_core PUBLIC cxx_std_23)
