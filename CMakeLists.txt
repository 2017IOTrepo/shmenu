cmake_minimum_required(VERSION 3.16)
project(shmenu C)

set(CMAKE_C_STANDARD 11)

add_executable(shmenu main.c main/actions.c main/actions.h ds/map.c ds/map.h values/constant.c values/constant.h)