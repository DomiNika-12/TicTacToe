cmake_minimum_required(VERSION 3.21)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe main.cpp Player.cpp Player.h Game.cpp Game.h)
