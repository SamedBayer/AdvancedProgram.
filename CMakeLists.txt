cmake_minimum_required(VERSION 3.1)
project(ODESolver VERSION 0.1.0 LANGUAGES CXX)
add_executable(ODESolver main.cpp Euler.cpp Explicit.cpp Implicit.cpp)
target_compile_features(ODESolver PRIVATE cxx_std_17)
set (CMAKE_CXX_FLAGS " -O2 -pg")

