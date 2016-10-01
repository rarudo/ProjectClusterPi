cmake_minimum_required(VERSION 3.6)
project(projectPi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp ipInfo.cpp ipInfo.h command.cpp command.h dnsInfo.cpp dnsInfo.h portInfo.cpp portInfo.h locationInfo.cpp locationInfo.h)
add_executable(projectPi ${SOURCE_FILES})
target_link_libraries(projectPi maxminddb)

