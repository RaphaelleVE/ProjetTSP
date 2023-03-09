cmake_minimum_required(VERSION 3.24)
project(challengeTSP)

set(CMAKE_CXX_STANDARD 17)

add_executable(challengeTSP main.cpp City.cpp City.h File.cpp File.h ScoreUtils.cpp ScoreUtils.h)
