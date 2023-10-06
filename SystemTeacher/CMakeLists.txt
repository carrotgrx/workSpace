cmake_minimum_required(VERSION 3.26)
project(SystemTeacher C)

set(CMAKE_C_STANDARD 11)

add_executable(SystemTeacher main.c
        lib.h
        view.c
        view.h
        api.c
        api.h)
