cmake_minimum_required(VERSION 3.10)

project(CalcRoute VERSION "2.0")

include_directories("D:\\clib\\mingw64\\include")
link_directories("D:\\clib\\mingw64\\lib")
# 编译时生成调试信息
list(APPEND CMAKE_CXX_FLAGS -g)

add_subdirectory(graph)

add_executable(CalcRoute CalcRoute.cpp)
