cmake_minimum_required(VERSION 3.26)
project(DataBase_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataBase_Management_System main.cpp
        Row.cpp
        Row.h
        Value.cpp
        Value.h
        Errors.h
        Storage.cpp
        Storage.h
        StorageBlock.cpp
        StorageBlock.h)
