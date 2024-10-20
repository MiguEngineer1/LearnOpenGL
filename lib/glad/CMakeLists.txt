cmake_minimum_required(VERSION 3.29) # Version may be different in the future

add_library(glad STATIC src/glad.c)

target_include_directories(glad PUBLIC include)