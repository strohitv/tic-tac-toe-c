cmake_minimum_required(VERSION 3.19)
project(11_tic_tac_toe C)

set(CMAKE_C_STANDARD 11)

add_executable(11_tic_tac_toe main.c game/utils.h game/utils.c game/score.h game/score.c game/player.h game/player.c game/ai.h game/ai.c main.h)