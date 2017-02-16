cmake_minimum_required(VERSION 3.6)
project(C__Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        GameMain.cpp
        Map.cpp
        Map.h
        Player.cpp
        Player.h
        Tile.cpp
        Tile.h)

add_executable(C__Game ${SOURCE_FILES})