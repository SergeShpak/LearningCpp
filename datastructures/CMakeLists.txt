cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME lcpp_datastructs)
set(CMAKE_CXX_COMPILER clang++)
add_compile_options("--std=c++11")
SET (LIBS_DIRECTORY ${CMAKE_SOURCE_DIR}/../libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBS_DIRECTORY})

project(${PROJECT_NAME})

include_directories(./include)
file(GLOB ARRAY_SRC ./src/array.cpp)

add_library(${PROJECT_NAME} ${ARRAY_SRC})
