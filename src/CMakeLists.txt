set(MATH_DIR ./math)
file(GLOB_RECURSE MATH_SOURCE_FILES ${MATH_DIR}/*.cpp)
file(GLOB_RECURSE MATH_HEADER_FILES ${MATH_DIR}/*.h)
add_library(Math ${MATH_SOURCE_FILES} ${MATH_HEADER_FILES})
target_include_directories(Math PUBLIC ${CMAKE_CURRENT_LIST_DIR})