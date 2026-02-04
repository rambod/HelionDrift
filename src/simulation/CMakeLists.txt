cmake_minimum_required(VERSION 4.1)
add_library(helion_simulation STATIC
        simulation.cpp
)

target_include_directories(helion_simulation
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(helion_simulation
        PUBLIC
        helion_core
)

target_compile_features(helion_simulation PUBLIC cxx_std_23)


