#include "../core/Loss.hpp"
#include <cmath>

class MSE : public Loss {
public:
    double compute(const std::vector<double>& y,
                   const std::vector<double>& y_hat) override {
        double sum = 0.0;
        for (size_t i = 0; i < y.size(); ++i) {
            double d = y[i] - y_hat[i];
            sum += d * d;
        }
        return sum / y.size();
    }

    std::vector<double> gradient(const std::vector<double>& y,
                                 const std::vector<double>& y_hat) override {
        std::vector<double> g(y.size());
        for (size_t i = 0; i < y.size(); ++i)
            g[i] = -2 * (y[i] - y_hat[i]) / y.size();
        return g;
    }
};