# cmake_minimum_required(VERSION <specify CMake version here>)
project(Projet)

set(CMAKE_CXX_STANDARD 98)

add_executable(Projet main.cpp Graphe.cpp Graphe.hpp Sommet.cpp Sommet.hpp Couple.cpp Couple.hpp)