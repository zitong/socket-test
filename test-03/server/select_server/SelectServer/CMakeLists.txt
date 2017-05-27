cmake_minimum_required(VERSION 3.7)
project(SelectServer)

set(CMAKE_CXX_STANDARD 11)
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(SOURCE_FILES main.cpp)
add_executable(SelectServer ${SOURCE_FILES})