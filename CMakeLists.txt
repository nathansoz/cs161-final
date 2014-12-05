cmake_minimum_required(VERSION 2.8)
project(Final)
include_directories("${PROJECT_BINARY_DIR}")

set(LIB_SRC
    Book.h
    Book.cpp
    Patron.h
    Patron.cpp
    Library.h
    Library.cpp
    menu.cpp
)
add_executable(library_sim ${LIB_SRC})


