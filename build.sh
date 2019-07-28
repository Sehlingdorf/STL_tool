#!/bin/bash

rm run.out *.stl

export CXXFLAGS="-O0 -g -std=c++11 -Wall -Wextra -Wsign-conversion -Wno-unused-parameter -Wno-empty-body -Wno-format-security"

echo "Building using gnu."
g++ $CXXFLAGS src/main.cpp src/triangle.cpp src/STL_tool.cpp src/surface_creation.cpp -o run.out

echo "Building using clang."
clang++ $CXXFLAGS src/main.cpp src/triangle.cpp src/STL_tool.cpp src/surface_creation.cpp -o run.out
