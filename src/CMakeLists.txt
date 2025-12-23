add_library(neural_net
    core/NeuralNet.hpp impl/DenseLayer.cpp impl/Activations.cpp impl/Losses.cpp impl/CSVLoader.cpp
)

target_include_directories(neural_net PUBLIC ../include)

add_executable(nn_demo main.cpp)
target_link_libraries(nn_demo neural_net)