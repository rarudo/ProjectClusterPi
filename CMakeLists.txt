cmake_minimum_required(VERSION 3.6)
project(projectPi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(SOURCE_FILES main.cpp ipAnalyse/ipInfo.cpp Command.cpp Command.h ipAnalyse/ipInfo.h ipAnalyse/dnsInfo.cpp ipAnalyse/dnsInfo.h Port.cpp Port.h ipAnalyse/locationInfo.cpp ipAnalyse/locationInfo.h mySql/MySQLConnWrapper.cpp mySql/MySQLConnWrapper.h mySql/Ipaddreses.cpp mySql/Ipaddreses.h Jobs.cpp Jobs.h)
set(SOURCE_FILES main.cpp ipAnalyse/ipInfo.cpp command.cpp command.h ipAnalyse/ipInfo.h ipAnalyse/dnsInfo.cpp ipAnalyse/dnsInfo.h Port.cpp Port.h ipAnalyse/locationInfo.cpp ipAnalyse/locationInfo.h mySql/MySQLConnWrapper.cpp mySql/MySQLConnWrapper.h mySql/Ipaddreses.cpp mySql/Ipaddreses.h Jobs.cpp Jobs.h mySql/TaskQue.cpp mySql/TaskQue.h)
#set(SOURCE_FILES main.cpp ipAnalyse/ipInfo.cpp ipAnalyse/ipInfo.h Command.cpp Command.h ipAnalyse/dnsInfo.cpp ipAnalyse/dnsInfo.h Port.cpp Port.h ipAnalyse/locationInfo.cpp ipAnalyse/locationInfo.h)
add_executable(projectPi ${SOURCE_FILES})
target_link_libraries(projectPi maxminddb)
target_link_libraries(projectPi mysqlcppconn)

