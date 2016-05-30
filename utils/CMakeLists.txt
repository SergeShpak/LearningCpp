cmake_minimum_required(VERSION 2.4)

set(PROJECT_NAME lcpputils)
project(${PROJECT_NAME})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB IO_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/io/*)

message("sources: ${IO_SRC}")

add_library(${PROJECT_NAME} SHARED ${IO_SRC})
