#pragma once
#include <vector>

class Layer {
public:
    virtual std::vector<double> forward(const std::vector<double>& input) = 0;
    virtual std::vector<double> backward(const std::vector<double>& grad, double lr) = 0;
    virtual ~Layer() = default;
};