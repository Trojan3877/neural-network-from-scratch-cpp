#include "../core/Activation.hpp"
#include <cmath>

class ReLU : public Activation {
public:
    double activate(double x) override { return x > 0 ? x : 0; }
    double derivative(double x) override { return x > 0 ? 1 : 0; }
};

class Sigmoid : public Activation {
public:
    double activate(double x) override { return 1.0 / (1.0 + std::exp(-x)); }
    double derivative(double x) override {
        double s = activate(x);
        return s * (1 - s);
    }
};