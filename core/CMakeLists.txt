cmake_minimum_required(VERSION 3.10)
project(core)

set(CMAKE_CXX_STANDARD 11)

add_executable(core main.cpp)
target_link_libraries (core curl)