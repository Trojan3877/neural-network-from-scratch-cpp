#include <gtest/gtest.h>
#include <memory>
#include <cmath>
#include "core/NeuralNet.hpp"
#include "impl/DenseLayer.hpp"
#include "impl/Activations.hpp"
#include "impl/Losses.hpp"

// ---------------------------------------------------------------------------
// Activation tests
// ---------------------------------------------------------------------------
TEST(ActivationTest, ReLUPositive) {
    ReLU relu;
    EXPECT_DOUBLE_EQ(relu.activate(3.0), 3.0);
}

TEST(ActivationTest, ReLUNegative) {
    ReLU relu;
    EXPECT_DOUBLE_EQ(relu.activate(-2.0), 0.0);
}

TEST(ActivationTest, ReLUDerivativePositive) {
    ReLU relu;
    EXPECT_DOUBLE_EQ(relu.derivative(1.0), 1.0);
}

TEST(ActivationTest, ReLUDerivativeNegative) {
    ReLU relu;
    EXPECT_DOUBLE_EQ(relu.derivative(-1.0), 0.0);
}

TEST(ActivationTest, SigmoidMidpoint) {
    Sigmoid sig;
    EXPECT_NEAR(sig.activate(0.0), 0.5, 1e-9);
}

TEST(ActivationTest, SigmoidDerivativeAtZero) {
    Sigmoid sig;
    // sigma'(0) = 0.5 * (1 - 0.5) = 0.25
    EXPECT_NEAR(sig.derivative(0.0), 0.25, 1e-9);
}

// ---------------------------------------------------------------------------
// Loss tests
// ---------------------------------------------------------------------------
TEST(LossTest, MSEZeroError) {
    MSE mse;
    EXPECT_DOUBLE_EQ(mse.compute({1.0, 2.0}, {1.0, 2.0}), 0.0);
}

TEST(LossTest, MSEKnownValue) {
    MSE mse;
    // (1-0)^2 + (1-0)^2 = 2, divided by 2 => 1.0
    EXPECT_DOUBLE_EQ(mse.compute({1.0, 1.0}, {0.0, 0.0}), 1.0);
}

TEST(LossTest, MSEGradientDirection) {
    MSE mse;
    // gradient = -2*(y - y_hat)/n; y=1, y_hat=0 => grad = -2
    auto g = mse.gradient({1.0}, {0.0});
    EXPECT_NEAR(g[0], -2.0, 1e-9);
}

// ---------------------------------------------------------------------------
// DenseLayer tests
// ---------------------------------------------------------------------------
TEST(DenseLayerTest, OutputSize) {
    DenseLayer layer(3, 2);
    auto out = layer.forward({1.0, 0.5, -1.0});
    EXPECT_EQ(out.size(), 2u);
}

TEST(DenseLayerTest, BackwardOutputSize) {
    DenseLayer layer(3, 2);
    layer.forward({1.0, 0.5, -1.0});
    auto grad_in = layer.backward({0.1, -0.2}, 0.01);
    EXPECT_EQ(grad_in.size(), 3u);
}

// ---------------------------------------------------------------------------
// NeuralNet integration tests
// ---------------------------------------------------------------------------
TEST(NeuralNetTest, ForwardOutputSize) {
    NeuralNet net(std::make_unique<MSE>());
    net.addLayer(std::make_unique<DenseLayer>(2, 3));
    net.addLayer(std::make_unique<DenseLayer>(3, 1));
    auto out = net.forward({0.5, 0.5});
    EXPECT_EQ(out.size(), 1u);
}

TEST(NeuralNetTest, TrainReducesLoss) {
    NeuralNet net(std::make_unique<MSE>());
    net.addLayer(std::make_unique<DenseLayer>(2, 4));
    net.addLayer(std::make_unique<DenseLayer>(4, 1));

    const std::vector<double> x = {0.9, 0.8};
    const std::vector<double> y = {1.0};
    const double lr = 0.01;

    double first_loss = net.train(x, y, lr);
    double later_loss = 0.0;
    for (int i = 0; i < 100; ++i)
        later_loss = net.train(x, y, lr);

    EXPECT_LT(later_loss, first_loss);
}
