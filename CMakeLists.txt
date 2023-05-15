cmake_minimum_required(VERSION 3.24)
project(challengeTSP)

set(CMAKE_CXX_STANDARD 17)

add_executable(challengeTSP main.cpp City.cpp City.h File.cpp File.h Solutions/Random.cpp Solutions/Random.h Solutions/Greedy.cpp Solutions/Greedy.h Solutions/Solution.cpp Solutions/Solution.h Solutions/Exchange.cpp Solutions/Exchange.h Solutions/Reinsertion.cpp Solutions/Reinsertion.h Solutions/TwoOpt.cpp Solutions/TwoOpt.h)
