cmake_minimum_required(VERSION 3.16)

project(projectTwo)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX FLAGS "{CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_INCLUDE_DIR "include")
set(CMAKE_SRC_DIR "src")

set(SOURCES ${CMAKE_SRC_DIR}/maxconnect4.cpp)

add_executable(maxconnect4 ${SOURCES})
target_include_directories(maxconnect4 PRIVATE ${CMAKE_INCLUDE_DIR})



