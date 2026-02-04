function(helion_enable_warnings target)
    if (MSVC)
        target_compile_options(${target} PRIVATE
                /W4
                /permissive-
                /w14242
                /w14254
                /w14263
                /w14265
                /w14287
                /we4289
                /w14296
                /w14311
                /w14545
                /w14546
                /w14547
                /w14549
                /w14555
                /w14619
                /w14640
                /w14826
                /w14905
                /w14906
                /w14928
        )
    else()
        target_compile_options(${target} PRIVATE
                -Wall
                -Wextra
                -Wpedantic
                -Wshadow
                -Wconversion
                -Wsign-conversion
                -Wundef
                -Wdouble-promotion
                -Wformat=2
                -Wnull-dereference
                -Wimplicit-fallthrough
        )

        if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            target_compile_options(${target} PRIVATE
                    -Wcomma
                    -Wshorten-64-to-32
            )
        endif()
    endif()
endfunction()

function(helion_warnings_as_errors target)
    if (MSVC)
        target_compile_options(${target} PRIVATE /WX)
    else()
        target_compile_options(${target} PRIVATE -Werror)
    endif()
endfunction()
