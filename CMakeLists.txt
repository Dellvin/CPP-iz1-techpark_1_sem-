cmake_minimum_required(VERSION 3.12)
project(hw_1 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpedantic")
set(CMAKE_CXX_FLAGS "--coverage")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories("${GTEST_INCLUDE_DIRS}")
include_directories(project/include)

add_executable(
        project/src/main.c
        project/include/arabiantorome.h
        project/src/arabiantorome.c)


add_executable(
        tests
        tests/main.cpp
        project/include/arabiantorome.h
        project/src/arabiantorome.c tests/mainTest.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads)


enable_testing()
add_test(tests "./tests")