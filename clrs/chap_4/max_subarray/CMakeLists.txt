cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER "clang++")
add_compile_options("-std=c++11")

include_directories(./include)

set(MAX_SUBARRAY_EXEC max_subarray)
file(GLOB MAX_SUBARRAY_SRC ./src/*)

add_executable(${MAX_SUBARRAY_EXEC} ${MAX_SUBARRAY_SRC})
