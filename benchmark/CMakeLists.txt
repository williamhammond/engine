include(FetchContent)
FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/williamhammond/benchmark.git
        GIT_TAG master)
SET(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
SET(BENCHMARK_ENABLE_WERROR OFF CACHE BOOL "" FORCE)
set(HAVE_STD_REGEX ON)
FetchContent_MakeAvailable(googlebenchmark)


set(MATH_DIR ./math)
file(GLOB_RECURSE MATH_TEST_FILES ${MATH_DIR}/*.cpp)
add_executable(math_benchmarks ${MATH_TEST_FILES})
target_link_libraries(math_benchmarks Math benchmark::benchmark gtest_main)

add_test(NAME math_benchmarks COMMAND math_benchmarks --benchmark_format=json --benchmark_out_format=json --benchmark_out=benchmark_result.json)
set_tests_properties(math_benchmarks PROPERTIES LABELS "benchmark")