cmake_minimum_required(VERSION 3.22)
project(Engine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BINARY_DIR build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
        )
FetchContent_MakeAvailable(fmt)

add_subdirectory(src/)

set(SOURCE_FILES src/main.cpp)
add_executable(Engine ${SOURCE_FILES})

target_link_libraries(Engine PUBLIC Math)

enable_testing()
add_subdirectory(test)
add_subdirectory(benchmark)

set(CMAKE_INSTALL_PREFIX "./build/install")
if (UNIX)
    include(GNUInstallDirs)
else ()
    if (WIN32)
        set(CMAKE_INSTALL_LIBDIR "lib")
        set(CMAKE_INSTALL_DATADIR "share")
        set(CMAKE_INSTALL_INCLUDEDIR "include")
        set(CMAKE_INSTALL_BINDIR "bin")
        message(STATUS "Setting installation destination on Windows to: ${CMAKE_INSTALL_PREFIX}")
    else ()
        message(FATAL_ERROR "System not UNIX nor WIN32 - not implemented yet")
    endif ()
endif ()
install(TARGETS Engine Math
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})