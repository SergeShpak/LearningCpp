cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(${CMAKE_SOURCE_DIR}/cmake_functions/CMakeLists.txt)  # join_paths()
join_paths(${PROJECT_SOURCE_DIR} "ext" EXT_PROJECTS_DIR)
join_paths(${EXT_PROJECTS_DIR} "gtest/build" EXT_GTEST_DIR)
set(RELATIVE_GTEST_LIBS_DIR src/googletest-build/googlemock/gtest)
join_paths(${EXT_GTEST_DIR} ${RELATIVE_GTEST_LIBS_DIR} GTEST_BINARY_DIR)
set(RELATIVE_GTEST_INCLUDE_DIR /src/googletest/googletest/include)
join_paths(${EXT_GTEST_DIR} ${RELATIVE_GTEST_INCLUDE_DIR} GTEST_INCLUDE_DIRS)
set(GTEST_LIB_NAME libgtest.a)
set(GTEST_MAIN_LIB_NAME libgtest_main.a)
join_paths(${GTEST_BINARY_DIR} ${GTEST_LIB_NAME} GTEST_LIB_PATH)
join_paths(${GTEST_BINARY_DIR} ${GTEST_MAIN_LIB_NAME} GTEST_MAIN_LIB_PATH)


IF (NOT EXISTS ${GTEST_LIB_PATH} OR NOT EXISTS ${GTEST_MAIN_LIB_PATH})
    add_subdirectory(${EXT_PROJECTS_DIR}/gtest ${GTEST_BINARY_DIR})
    set(BUILDING_GTEST 1)
ENDIF (NOT EXISTS ${GTEST_LIB_PATH} OR NOT EXISTS ${GTEST_MAIN_LIB_PATH})

set(GTEST_LIBS_PATHS ${GTEST_LIB_PATH} ${GTEST_MAIN_LIB_PATH})
message("++Libs dir: ${GTEST_LIBS_PATHS}  source_dir: ${GTEST_INCLUDE_DIR}")
set(CMAKE_EXE_LINKER_FLAGS "-lpthread")

set(TESTED_LIBS_DIR ${CMAKE_SOURCE_DIR}/../libs)

add_subdirectory(${CMAKE_SOURCE_DIR}/datastructures)
