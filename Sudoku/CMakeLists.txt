cmake_minimum_required(VERSION 3.26)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sudoku main.cpp
        include/Tablero.h
        include/Casilla.h
        include/Grupo.h)
