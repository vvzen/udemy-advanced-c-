# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Name of the project
project(sets)

# Flags for the compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# What to compile
add_executable(
	bin/sets
	sets.cpp	
)

