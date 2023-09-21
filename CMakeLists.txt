cmake_minimum_required(VERSION 3.23)
project(3DVector)

set(CMAKE_CXX_STANDARD 23)

#TODO: Refactor this so src/ won't be necessary
add_executable(3DVector src/main.cpp src/Vectors.h src/Render.cpp src/Render.h
)
