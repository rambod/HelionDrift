cmake_minimum_required(VERSION 4.1)
project(HelionDrift
        VERSION 0.1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/core)
add_subdirectory(src/simulation)
add_subdirectory(src/app)
