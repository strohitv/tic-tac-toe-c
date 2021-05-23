cmake_minimum_required(VERSION 3.19)
project(11_tic_tac_toe C)

set(CMAKE_C_STANDARD 11)

add_executable(11_tic_tac_toe main.c utils.h utils.c score.h score.c player.h player.c ai.h ai.c main.h)