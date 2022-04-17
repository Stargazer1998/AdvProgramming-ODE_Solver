cmake_minimum_required(VERSION 3.1)
project(ExpilicitSolver VERSION 0.1.0 LANGUAGES CXX)
add_executable(ExpilicitSolver main.cpp CreateTimeDomain.cpp Euler.cpp  GetSolution.cpp Heun.cpp MatrixOperations.cpp RHS.cpp RungeKutta.cpp TestFunction.cpp)


