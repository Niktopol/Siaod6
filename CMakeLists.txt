cmake_minimum_required(VERSION 3.20)

project(Siaod6)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wall -Wpedantic -fsanitize=address -g")
add_executable(Siaod6 main.cpp graph.cpp)