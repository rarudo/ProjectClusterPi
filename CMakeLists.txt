cmake_minimum_required(VERSION 3.6)
project(projectPi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp ipAnalyse/ipInfo.cpp ipAnalyse/ipInfo.h command.cpp command.h ipAnalyse/dnsInfo.cpp ipAnalyse/dnsInfo.h portInfo.cpp portInfo.h ipAnalyse/locationInfo.cpp ipAnalyse/locationInfo.h mySql/mysqlconn_wrapper.cpp mySql/mysqlconn_wrapper.h)
add_executable(projectPi ${SOURCE_FILES})
target_link_libraries(projectPi maxminddb)

