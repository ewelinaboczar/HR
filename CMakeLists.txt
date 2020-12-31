cmake_minimum_required( VERSION 3.0 )

project(LABORATORIUM_5)

include_directories( ./src ./include)

add_executable(test ./src/main.cpp ./src/employee.cpp ./src/HRMS.cpp)