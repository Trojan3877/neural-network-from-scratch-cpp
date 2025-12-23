#pragma once
#include <vector>

class Activation {
public:
    virtual double activate(double x) = 0;
    virtual double derivative(double x) = 0;
    virtual ~Activation() = default;
};