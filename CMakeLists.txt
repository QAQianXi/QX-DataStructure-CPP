cmake_minimum_required(VERSION 3.24)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure SqList.cpp LinkList.cpp Test/P17--SqList.cpp)
add_executable(LinkList LinkList.cpp)
add_executable(2--SqList Test/P17--SqList.cpp)