cmake_minimum_required(VERSION 2.8)

set(CMAKE_FUNCTIONS ${CMAKE_CURRENT_SOURCE_DIR}/../cmake_functions/CMakeLists.txt)
include(${CMAKE_FUNCTIONS})

set(PROJECT_NAME datastructures_testing)

project(${PROJECT_NAME})
file(GLOB SRC ./src/*.cpp)
set(TESTED_LIBS_NAMES liblcpp_datastructs.a)
set(DATASTRUCTURES_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/../../datastructures/include)

message("++ DATASTRUCTURES_INCLUDE_DIR: ${DATASTRUCTURES_INCLUDE_DIR}")

include_directories(${GTEST_INCLUDE_DIRS} ${DATASTRUCTURES_INCLUDE_DIR})
message("++datastructs - include_directories: ${GTEST_INCLUDE_DIRS}")
add_executable(${PROJECT_NAME} ${SRC})

add_dependencies(${PROJECT_NAME} ${GTEST_DEPENDENCY})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBS_PATHS})

set(TESTED_LIBS_PATHS "")
set(LIB_PATH "")
foreach(library_name IN LISTS TESTED_LIBS_NAMES)
    join_paths(${TESTED_LIBS_DIR} ${library_name} LIB_PATH)
    STRING(CONCAT TESTED_LIBS_PATHS ${TESTED_LIBS_PATHS} ${LIB_PATH})
endforeach(library_name)
message("++ LIBS paths:${TESTED_LIBS_PATHS}")
target_link_libraries(${PROJECT_NAME} ${TESTED_LIBS_PATHS})
