# This needs to be googletest, not gtest https://github.com/google/googletest/issues/2457
# or else it'll break MSVC
FetchContent_Declare(
        googletest
        QUIET
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz)
set(gtest_force_shared_crt
        ON
        CACHE BOOL "" FORCE)
set(BUILD_GMOCK
        ON
        CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(MATH_DIR ./math)
file(GLOB_RECURSE MATH_TEST_FILES ${MATH_DIR}/*.cpp)
add_executable(math_tests ${MATH_TEST_FILES})

target_link_libraries(math_tests PUBLIC Math gtest_main fmt)

if (MSVC)
    target_compile_options(math_tests PRIVATE /W4 /WX)
else ()
    target_compile_options(math_tests PRIVATE -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wundef -Wconversion -Werror)
endif ()

include(GoogleTest)
gtest_discover_tests(
        math_tests
        PROPERTIES LABELS "unit" DISCOVERY_TIMEOUT # how long to wait (in seconds)
        # before crashing
        240)

set(GRAPHICS_DIR ./graphics)
file(GLOB_RECURSE GRAPHICS_TEST_FILES ${GRAPHICS_DIR}/*.cpp)
add_executable(graphics_tests ${GRAPHICS_TEST_FILES})

target_link_libraries(graphics_tests PUBLIC Graphics gtest_main fmt)

if (MSVC)
    target_compile_options(graphics_tests PRIVATE /W4 /WX)
else ()
    target_compile_options(graphics_tests PRIVATE -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wundef -Wconversion -Werror)
endif ()

gtest_discover_tests(
        graphics_tests
        PROPERTIES LABELS "unit" DISCOVERY_TIMEOUT # how long to wait (in seconds)
        # before crashing
        240)
