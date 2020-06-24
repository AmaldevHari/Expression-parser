cmake_minimum_required(VERSION 3.16)


project(run)

include_directories(src)

add_executable(run src/expression_parser.cpp src/main.cpp)


