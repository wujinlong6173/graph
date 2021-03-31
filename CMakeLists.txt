cmake_minimum_required(VERSION 3.10)

project(CalcRoute VERSION "2.0")

add_subdirectory(graph)

add_executable(CalcRoute CalcRoute.cpp)
