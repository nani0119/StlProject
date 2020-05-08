cmake_minimum_required(VERSION 3.10)

project(QtCppExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QtCppExample main.cpp)
install(TARGETS QtCppExample DESTINATION bin)
