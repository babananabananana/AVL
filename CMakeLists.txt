cmake_minimum_required(VERSION 3.15)
project(AVL)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVL main.cpp NodeInterface.h AVLInterface.h AVL.h AVL.cpp Node.h Node.cpp)