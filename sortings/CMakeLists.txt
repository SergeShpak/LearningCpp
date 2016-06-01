cmake_minimum_required(VERSION 3.2.3)

set(CMAKE_CXX_COMPILER clang++)
add_compile_options("-std=c++11")

option(V "Verbose mode" OFF)

set(PROJECT_NAME sorting)
project(${PROJECT_NAME})

IF(NOT ALGO_DEFINITION)
    message(FATAL_ERROR "No algorithm specified (use ALGO_DEFINITION option)")
ENDIF(NOT ALGO_DEFINITION)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(REPORTING_SRC ${SRC_DIR}/reporting.cpp)

###############################################################################
##  Algorithms section
###############################################################################

set(ALGO_SRC_DIR "")
set(ALGO_EXEC "")

IF(${ALGO_DEFINITION} STREQUAL "BubbleSort")
    set(ALGO_SRC_DIR ${SRC_DIR}/bubble)
    set(ALGO_EXEC bubble)
ELSEIF(${ALGO_DEFINITION} STREQUAL "InsertionSort")
    set(ALGO_SRC_DIR ${SRC_DIR}/insertion)
    set(ALGO_EXEC insertion)
ELSEIF(${ALGO_DEFINITION} STREQUAL "MergeSort")
    set(ALGO_SRC_DIR ${SRC_DIR}/merge)
    set(ALGO_EXEC merge)
ELSE(${ALGO_DEFINITION} STREQUAL "BubbleSort")
    message(FATAL_ERROR "Algorithm ${ALGO_DEFINITION} is not implemented")
ENDIF(${ALGO_DEFINITION} STREQUAL "BubbleSort")

file(GLOB ALGO_SRC ${ALGO_SRC_DIR}/*)

###############################################################################
##  End of algorithm section
###############################################################################

IF(V)
    message(STATUS "++ Chosen algorithm: ${ALGO_DEFINITION}")
    message(STATUS "++ Algorithm source dir: ${ALGO_SRC_DIR}")
    message(STATUS "++ Algorithm source files: ${ALGO_SRC}")
ENDIF(V)

add_executable(${ALGO_EXEC} ${ALGO_SRC} ${REPORTING_SRC})
