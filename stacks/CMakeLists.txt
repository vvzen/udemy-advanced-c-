# Specify the minimum version of CMAKE
cmake_minimum_required(VERSION 2.8)

# Project name
project(stacks)

# Support for C++11
set(CMAKE_CXX_STANDARD 11)

# Where to compile and what
add_executable(
    bin/stacks
    stacks.cpp
)
