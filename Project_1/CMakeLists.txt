cmake_minimum_required(VERSION 3.16)

project(projectOne)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_INCLUDE_DIR "include")
set(CMAKE_SRC_DIR "src")

set(SOURCES ${CMAKE_SRC_DIR}/find_route.cpp)

add_executable(find_route ${SOURCES})
target_include_directories(find_route PRIVATE ${CMAKE_INCLUDE_DIR})


