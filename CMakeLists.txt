cmake_minimum_required(VERSION 3.21)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5 main.cpp Director.cpp Director.h accountant.cpp accountant.h admin.cpp admin.h security.cpp security.h Employee.cpp Employee.h FIO.cpp FIO.h Salary.cpp Salary.h)
