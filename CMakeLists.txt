cmake_minimum_required(VERSION 3.26)
project(cses)

set(CMAKE_CXX_STANDARD 17)

add_executable(towers sorting/towers.cpp)
add_executable(traffic sorting/trafficLights.cpp)
add_executable(josephesProblemEasy sorting/josephesProblem1.cpp)
add_executable(NestedRangeCheck sorting/NestedRangeCheck.cpp)
add_executable(josephesProblem sorting/josephesProblem.cpp)