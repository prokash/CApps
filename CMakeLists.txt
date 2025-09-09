cmake_minimum_required(VERSION 3.28.6)
project(CApps C)

set(CMAKE_C_STANDARD 11)

add_executable(CApps main.c
        Q.c
        Q.h
        str.c
        str.h
        list.c
        list.h
        arr.c
        arr.h
        tree.c
        tree.h
        algo.c
        algo.h
        quiz.c
        quiz.h
        problems.c
        problems.h)
