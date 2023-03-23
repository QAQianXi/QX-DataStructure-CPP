cmake_minimum_required(VERSION 3.24)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure SqList.cpp LinkList.cpp)
add_executable(LinkList LinkList.cpp)