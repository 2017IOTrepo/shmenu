cmake_minimum_required(VERSION 3.16)
project(shmenu C)

set(CMAKE_C_STANDARD 11)

add_executable(shmenu main.c actions.c actions.h map.c map.h constant.c constant.h)