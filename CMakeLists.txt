cmake_minimum_required(VERSION 3.20)
project(lab5-sogent)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab5-sogent
        CS201L_Fall2021_Lab05-1.docx
        lab05.cpp
        README.md calcFuelEconomy.cpp calcFuelEconomy.h)