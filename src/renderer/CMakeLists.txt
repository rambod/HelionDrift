add_library(helion_renderer STATIC
        renderer.cpp
)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(helion_renderer
        PUBLIC
        raylib
        glfw
        helion_core
)

target_include_directories(helion_renderer
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(helion_renderer PUBLIC cxx_std_23)
