cmake_minimum_required(VERSION 3.16)
project(NeuralNetworkFromScratch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# All headers live under src/; use "core/..." or "impl/..." includes
include_directories(src)

add_executable(neural_net
    src/main.cpp
    src/impl/NeuralNet.cpp
    src/impl/CSVLoader.cpp
)

enable_testing()
add_subdirectory(tests)
