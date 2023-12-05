cmake_minimum_required(VERSION 3.20)
project(artProgram)

set(CMAKE_CXX_STANDARD 14)

add_executable(artProgram main.cpp main.cpp paintMethods.cpp paintMethods.h coreMethods.cpp coreMethods.h folderMethods.cpp folderMethods.h)
