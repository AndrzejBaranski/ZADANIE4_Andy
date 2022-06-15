cmake_minimum_required(VERSION 3.22)
project(ZADANIE4_Andy)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZADANIE4_Andy main.cpp logger_andy.h logger_andy.cpp BEERCALCULATION.cpp BEERCALCULATION.h HAMMINGDISTANCE.cpp HAMMINGDISTANCE.h createFile.cpp createFile.h timeStamp.cpp timeStamp.h)
