cmake_minimum_required(VERSION 3.13)
project(mcst)

set(CMAKE_CXX_STANDARD 14)

add_executable(mcst main.cpp Tree.cpp Tree.h TicTacToeState.cpp TicTacToeState.h TicTacTurn.cpp TicTacTurn.h MCNode.cpp MCNode.h)