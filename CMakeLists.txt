cmake_minimum_required(VERSION 3.10)

project(aos-vs-soa)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(main main.cpp)
