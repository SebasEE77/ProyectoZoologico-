cmake_minimum_required(VERSION 3.24)
project(zoologico)

set(CMAKE_CXX_STANDARD 17)

add_executable(zoologico main.cpp zoologico.cpp zoologico.h animales.h habitat.h habitat.cpp animales.cpp AccionAnimal.h AccionAnimal.cpp dieta.h dieta.cpp)
