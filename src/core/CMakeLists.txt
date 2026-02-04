add_library(helion_core STATIC
        core.cpp
        log.cpp
        log.h
        assert.cpp
        assert.h
        profiler.cpp
        profiler.h
)

helion_enable_warnings(helion_core)
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    helion_warnings_as_errors(helion_core)
endif()


target_include_directories(helion_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(helion_core PUBLIC cxx_std_23)
