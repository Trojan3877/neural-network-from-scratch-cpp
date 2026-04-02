#include <iostream>
#include <memory>
#include <vector>
#include "core/NeuralNet.hpp"
#include "impl/DenseLayer.hpp"
#include "impl/Activations.hpp"
#include "impl/Losses.hpp"

int main() {
    std::cout << "Neural Network from Scratch (C++) Demo\n";
    std::cout << "---------------------------------------\n";

    // Build a 2 -> 4 -> 1 network with MSE loss
    NeuralNet net(std::make_unique<MSE>());
    net.addLayer(std::make_unique<DenseLayer>(2, 4));
    net.addLayer(std::make_unique<DenseLayer>(4, 1));

    // Simple binary classification training data
    using Sample = std::pair<std::vector<double>, std::vector<double>>;
    std::vector<Sample> data = {
        {{0.1, 0.2}, {0.0}},
        {{0.2, 0.1}, {0.0}},
        {{0.8, 0.9}, {1.0}},
        {{0.9, 0.8}, {1.0}},
    };

    const double lr      = 0.01;
    const int    epochs  = 1000;

    for (int epoch = 0; epoch <= epochs; ++epoch) {
        double total_loss = 0.0;
        for (auto& [x, y] : data)
            total_loss += net.train(x, y, lr);
        if (epoch % 200 == 0)
            std::cout << "Epoch " << epoch
                      << "  avg-loss: " << total_loss / static_cast<double>(data.size())
                      << "\n";
    }

    std::cout << "\nSample predictions after training:\n";
    for (auto& [x, y] : data) {
        auto pred = net.forward(x);
        std::cout << "  input=[" << x[0] << ", " << x[1]
                  << "]  target=" << y[0]
                  << "  predicted=" << pred[0] << "\n";
    }

    return 0;
}
