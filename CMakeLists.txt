cmake_minimum_required(VERSION 3.16)
project(NeuralNetCPP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include src)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)