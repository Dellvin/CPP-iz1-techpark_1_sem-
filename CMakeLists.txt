cmake_minimum_required(VERSION 3.9)
project(hw_1 C)
enable_language(C CXX)
set(CMAKE_C_FLAGS  "-std=c11")

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(tests)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/project/include/*.h"
        "${PROJECT_SOURCE_DIR}/project/src/*.c"
        "${PROJECT_SOURCE_DIR}/project/src/*.cpp")

add_executable(hw_1 ${sources})
