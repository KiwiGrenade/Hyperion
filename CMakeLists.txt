cmake_minimum_required(VERSION 3.23)
project(3DVector)

set(CMAKE_CXX_STANDARD 23)

add_executable(3DVector Vector3D.cpp Vectors.h Render.cpp Render.h)
