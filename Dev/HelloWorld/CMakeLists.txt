cmake_minimum_required (VERSION 3.5)

project (HelloWorld)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_executable(HelloWorld
    src/Main.cpp
    src/Log.cpp
)