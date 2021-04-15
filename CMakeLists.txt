cmake_minimum_required(VERSION 3.16)
project(myos C)

set(CMAKE_C_STANDARD 11)

add_executable(myos
        cpu_api/p3.c)
