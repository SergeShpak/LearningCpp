cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_CXX_COMPILER clang++)
add_compile_options("-std=c++11")

set(PROJECT_NAME sorting)
project(${PROJECT_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(BUBBLE_S_DIR ${SRC_DIR}/bubble)
set(BUBBLE_EXEC bubble)
file(GLOB BUBBLE_SRC ${BUBBLE_S_DIR}/*)

add_executable(${BUBBLE_EXEC} ${BUBBLE_SRC})

set(INSERTION_S_DIR ${SRC_DIR}/insertion)
set(INSERTION_EXEC insertion)
file(GLOB INSERTION_SRC ${INSERTION_S_DIR}/*)

add_executable(${INSERTION_EXEC} ${INSERTION_SRC})
