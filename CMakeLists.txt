cmake_minimum_required(VERSION 3.3)
project(second)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NelderMidAlgorithm.cpp NelderMidAlgorithm.h SElement.cpp SElement.h SequenceArg.cpp SequenceArg.h)
add_executable(second ${SOURCE_FILES})