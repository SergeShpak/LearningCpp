cmake_minimum_required(VERSION 3.2.3)

set(CMAKE_CXX_COMPILER clang++)
add_compile_options("-std=c++11")

set(PROJECT_NAME sorting)
project(${PROJECT_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(ALGO_DEFINITION SORTING_ALGO)
set(MAIN_SRC ${SRC_DIR}/main.cpp ${SRC_DIR}/reporting.cpp)

set(BUBBLE_S_DIR ${SRC_DIR}/bubble)
set(BUBBLE_EXEC bubble)
file(GLOB BUBBLE_SRC ${BUBBLE_S_DIR}/*)
add_executable(${BUBBLE_EXEC} ${BUBBLE_SRC} ${MAIN_SRC})
target_compile_definitions(${BUBBLE_EXEC} PRIVATE 
                                                ${ALGO_DEFINITION}=BubbleSort)

set(INSERTION_S_DIR ${SRC_DIR}/insertion)
set(INSERTION_EXEC insertion)
file(GLOB INSERTION_SRC ${INSERTION_S_DIR}/*)
add_executable(${INSERTION_EXEC} ${INSERTION_SRC} ${BUBBLE_SRC} ${MAIN_SRC})
target_compile_definitions(${INSERTION_EXEC} PRIVATE 
                                            ${ALGO_DEFINITION}=InsertionSort)

#[[
add_executable(${BUBBLE_EXEC} ${BUBBLE_SRC})

set(INSERTION_S_DIR ${SRC_DIR}/insertion)
set(INSERTION_EXEC insertion)
file(GLOB INSERTION_SRC ${INSERTION_S_DIR}/*)

add_executable(${INSERTION_EXEC} ${INSERTION_SRC})

set(MERGE_S_DIR ${SRC_DIR}/merge)
set(MERGE_EXEC merge)
file(GLOB MERGE_SRC ${MERGE_S_DIR}/*)

add_executable(${MERGE_EXEC} ${MERGE_SRC})
]]
