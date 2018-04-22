cmake_minimum_required(VERSION 3.10)
project(core)

set(CMAKE_CXX_STANDARD 11)

add_executable(core main.cpp src/TaskReq.cpp includes/TaskReq.h src/Task.cpp includes/Task.h src/Tasks.cpp includes/Tasks.h)
target_link_libraries (core curl)
#target_link_libraries (core RapidJSON)
