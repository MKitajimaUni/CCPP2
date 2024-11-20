cmake_minimum_required(VERSION 3.29)
project(c)

set(CMAKE_C_STANDARD 11)

add_executable(c
        Main.c
        FileReader.h
        FileReader.c
        Cousins.c
        Cousins.h
        )
