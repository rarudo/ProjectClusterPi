cmake_minimum_required(VERSION 3.6)
project(projectPi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp ipInfo.cpp ipInfo.h command.cpp command.h)
add_executable(projectPi ${SOURCE_FILES})