cmake_minimum_required(VERSION 3.16)
project(myos VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)

include(CTest)
enable_testing()

add_executable(myos main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
