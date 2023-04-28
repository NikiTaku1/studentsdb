cmake_minimum_required(VERSION 3.23)
project(student_database)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(student_database
        dbgen.cpp
        AVLTree.h
)
