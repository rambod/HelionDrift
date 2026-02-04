add_library(helion_simulation STATIC
        simulation.cpp
)

helion_enable_warnings(helion_simulation)
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    helion_warnings_as_errors(helion_simulation)
endif()



target_include_directories(helion_simulation
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(helion_simulation
        PUBLIC
        helion_core
)

target_compile_features(helion_simulation PUBLIC cxx_std_23)


