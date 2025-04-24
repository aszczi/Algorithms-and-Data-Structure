cmake_minimum_required(VERSION 3.30)
project(Floyd_Warshall)

set(CMAKE_CXX_STANDARD 20)

add_executable(Floyd_Warshall main.cpp Graf.h Graf.cpp edge.h edge.cpp)
