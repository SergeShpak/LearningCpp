cmake_minimum_required(VERSION 2.9)
set(EXEC coins)
project(${EXEC})

set(CMAKE_CXX_COMPILER clang++)

set(SRC_DIRECTORY ./src)
file(GLOB SRC "${SRC_DIRECTORY}/*.cpp")
include_directories(./include)

add_executable(${EXEC} ${SRC})
