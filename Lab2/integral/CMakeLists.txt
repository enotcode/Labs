cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp integral.h integral.cpp)
add_executable(project ${SOURCE_FILES})