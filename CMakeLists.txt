cmake_minimum_required(VERSION 3.0)

project(bioeditor)

add_executable(bioeditor main.cpp)

install(TARGETS bioeditor RUNTIME DESTINATION bin)
