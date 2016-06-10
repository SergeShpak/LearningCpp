cmake_minimum_required(VERSION 2.8)

include(${CMAKE_SOURCE_DIR}/cmake_functions/CMakeLists.txt)  # join_paths()
join_paths(${PROJECT_SOURCE_DIR} "ext" EXT_PROJECTS_DIR)
join_paths(${CMAKE_BINARY_DIR} "ext" GTEST_BINARY_DIR)

join_paths($ENV{HOME} "googletest" GTEST_DIR)
join_paths(${GTEST_DIR} "CMakeLists.txt" GTEST_CMAKE_FILE)
IF (EXISTS ${GTEST_CMAKE_FILE})
    message("++ Found gtest sources")
    add_subdirectory(${GTEST_DIR} ${GTEST_BINARY_DIR})
    join_paths(${GTEST_DIR} "googletest/include" GTEST_INCLUDE_DIRS)
    join_paths(${GTEST_BINARY_DIR} "googlemock/gtest" GTEST_LIBS_DIR)
    set(GTEST_DEPENDENCY gtest gtest_main)
ENDIF(EXISTS ${GTEST_CMAKE_FILE})
IF (NOT EXISTS ${GTEST_CMAKE_FILE})
    add_subdirectory(${EXT_PROJECTS_DIR}/gtest ${GTEST_BINARY_DIR})
    set(GTEST_DEPENDENCY "googletest")
ENDIF (NOT EXISTS ${GTEST_CMAKE_FILE})
message("++Libs dir: ${GTEST_LIBS_DIR}  source_dir: ${GTEST_INCLUDE_DIRS}")
set(GTEST_LIBS_PATHS ${GTEST_LIBS_DIR}/libgtest.a 
                        ${GTEST_LIBS_DIR}/libgtest_main.a)
set(CMAKE_EXE_LINKER_FLAGS "-lpthread")

set(TESTED_LIBS_DIR ${CMAKE_SOURCE_DIR}/../libs)

add_subdirectory(${CMAKE_SOURCE_DIR}/datastructures)
