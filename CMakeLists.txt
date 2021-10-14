cmake_minimum_required(VERSION 3.8)
project(IZ1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -ggdb3 ")

# Library
add_library(date STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/date.c)
target_include_directories(date PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Main
add_executable(main
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main date)

#Tests
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest)
enable_testing()

add_executable(tests tests/tests.cpp)

target_include_directories(tests
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(tests
        gtest_main
        date)

# Coverage
target_compile_options(date PRIVATE --coverage)
target_link_libraries(date INTERFACE --coverage)

