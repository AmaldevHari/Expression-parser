cmake_minimum_required(VERSION 3.16)


project(run)

include_directories(.)

add_executable(run expression_parser.cpp main.cpp)


