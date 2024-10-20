cmake_minimum_required(VERSION 3.29)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 20)

# Add GLFW
add_subdirectory(lib/glfw-3.4)
include_directories(lib/glfw-3.4/include)

# Add GLAD
add_subdirectory(lib/glad)
include_directories(lib/glad/include)

add_executable(LearnOpenGL src/main.cpp)

# Link GLFW
target_link_libraries(LearnOpenGL glfw)

# Link GLAD
target_link_libraries(LearnOpenGL glad)