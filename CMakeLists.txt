cmake_minimum_required(VERSION 3.16)
project(NeuralNetworkFromScratch)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(neural_net
    src/main.cpp
    src/neural_network.cpp
    src/activation.cpp
    src/loss.cpp
)
