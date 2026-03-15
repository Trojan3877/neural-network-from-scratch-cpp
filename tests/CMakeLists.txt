#include <cassert>
#include "neural_network.h"

int main() {
    NeuralNetwork nn({2, 4, 1});
    auto output = nn.forward({0.1, 0.9});

    assert(output.size() == 1);
    return 0;
}
