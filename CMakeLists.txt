cmake_minimum_required(VERSION 4.1)
project(HelionDrift
        VERSION 0.1.0
        LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CompilerWarnings)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_custom_target(format
        COMMAND clang-format -i
        ${CMAKE_SOURCE_DIR}/src/app/main.cpp
        ${CMAKE_SOURCE_DIR}/src/core/core.cpp
        ${CMAKE_SOURCE_DIR}/src/simulation/simulation.cpp
)

add_subdirectory(src/core)
add_subdirectory(src/simulation)
add_subdirectory(src/app)
