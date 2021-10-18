# CMakeList.txt : CMake project for ProjectHype, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ProjectHype")
set(SOURCES src/TicTacToe.cpp src/AI.cpp inc/AI.h)
# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCES})

# TODO: Add tests and install targets if needed.
