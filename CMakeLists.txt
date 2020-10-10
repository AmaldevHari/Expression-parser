cmake_minimum_required(VERSION 3.16)


project(run)

include_directories(include)

add_executable(run src/expression_parser.cpp src/integral_calculator.cpp src/main.cpp)

add_library(expression_parser SHARED src/expression_parser.cpp src/integral_calculator.cpp)

install(TARGETS expression_parser run
	LIBRARY  DESTINATION lib
	RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/expression_parser.hpp
	 DESTINATION include)



