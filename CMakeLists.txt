cmake_minimum_required(VERSION 3.24)
project(challengeTSP)

set(CMAKE_CXX_STANDARD 17)

add_executable(challengeTSP main.cpp City.cpp City.h File.cpp File.h Solutions/Random.cpp Solutions/Random.h Solutions/Greedy.cpp Solutions/Greedy.h Solutions/Solution.cpp Solutions/Solution.h Solutions/Strategies/Exchange.cpp Solutions/Strategies/Exchange.h Solutions/Strategies/Reinsertion.cpp Solutions/Strategies/Reinsertion.h Solutions/Strategies/TwoOpt.cpp Solutions/Strategies/TwoOpt.h Solutions/LocalSearch.cpp Solutions/LocalSearch.h Solutions/Strategies/NeighborStart.cpp Solutions/Strategies/NeighborStart.h)
