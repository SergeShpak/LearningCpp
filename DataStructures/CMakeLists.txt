cmake_minimum_required(VERSION 2.4)

set(PROJECT_NAME data_structures)
project (${PROJECT_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(ARRAY_DIRRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/array)

message(${ARRAY_DIRRECTORY})

file(GLOB ARRAY_FILES ${ARRAY_DIRRECTORY}/*)

message(STATUS ${ARRAY_FILES})

add_library(${PROJECT_NAME} SHARED ${ARRAY_FILES})
