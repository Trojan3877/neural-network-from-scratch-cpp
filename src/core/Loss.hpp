#pragma once
#include <vector>

class Loss {
public:
    virtual double compute(const std::vector<double>& y,
                           const std::vector<double>& y_hat) = 0;
    virtual std::vector<double> gradient(const std::vector<double>& y,
                                         const std::vector<double>& y_hat) = 0;
    virtual ~Loss() = default;
};