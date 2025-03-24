cmake_minimum_required(VERSION 3.30)
project(BFS_and_DFS)

set(CMAKE_CXX_STANDARD 20)

add_executable(BFS_and_DFS main.cpp
        BFS.cpp
        BFS.h
        DFS.cpp
        DFS.h)
