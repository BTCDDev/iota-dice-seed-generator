cmake_minimum_required(VERSION 3.8)
project(iota-dice-seed-generator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(iota-dice-seed-generator ${SOURCE_FILES})
