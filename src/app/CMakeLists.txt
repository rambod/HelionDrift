add_executable(helion_drift
        main.cpp
        Application.cpp
        Application.h
)

helion_enable_warnings(helion_drift)
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    helion_warnings_as_errors(helion_drift)
endif()


target_link_libraries(helion_drift
        PRIVATE
        helion_simulation
        helion_core
        helion_renderer
)

target_compile_features(helion_drift PRIVATE cxx_std_23)
