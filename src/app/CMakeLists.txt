cmake_minimum_required(VERSION 4.1)
add_executable(helion_drift
        main.cpp
)

target_link_libraries(helion_drift
        PRIVATE
        helion_simulation
        helion_core
)

target_compile_features(helion_drift PRIVATE cxx_std_23)
