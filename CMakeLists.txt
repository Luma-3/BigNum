cmake_minimum_required(VERSION 3.5)
project(Test CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

add_executable(test 
	source/main.cpp
	source/BigInt/BigInt.cpp
	source/BigInt/print.cpp
	source/BigInt/operation.cpp
	source/BigInt/operatorArithmetic.cpp)

target_include_directories(test PRIVATE include)