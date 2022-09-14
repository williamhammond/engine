set(MATH_DIR ./math)
file(GLOB_RECURSE MATH_SOURCE_FILES ${MATH_DIR}/*.cpp)
file(GLOB_RECURSE MATH_HEADER_FILES ${MATH_DIR}/*.h)
add_library(Math ${MATH_SOURCE_FILES} ${MATH_HEADER_FILES})

target_include_directories(Math PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if (MSVC)
    target_compile_options(Math PRIVATE /W4 /WX)
else ()
    target_compile_options(Math PRIVATE -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wundef -Wconversion -Werror)
endif ()

set(GRAPHICS_DIR ./graphics)
file(GLOB_RECURSE GRAPHICS_SOURCE_FILES ${GRAPHICS_DIR}/*.cpp)
file(GLOB_RECURSE GRAPHICS_HEADER_FILES ${GRAPHICS_DIR}/*.h)
add_library(Graphics ${GRAPHICS_SOURCE_FILES} ${GRAPHICS_HEADER_FILES})

target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if (MSVC)
    target_compile_options(Graphics PRIVATE /W4 /WX)
else ()
    target_compile_options(Graphics PRIVATE -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wundef -Wconversion -Werror)
endif ()
target_link_libraries(Graphics PUBLIC Math)
