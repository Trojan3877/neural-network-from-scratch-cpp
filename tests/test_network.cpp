#include <gtest/gtest.h>
#include <memory>
#include <cmath>
#include "core/NeuralNet.hpp"
#include "impl/DenseLayer.hpp"
#include "impl/Activations.hpp"
#include "impl/Losses.hpp"

// ── DenseLayer tests ─────────────────────────────────────────────────────────

TEST(DenseLayerTest, ForwardOutputSize) {
    DenseLayer layer(3, 2, 42);
    auto out = layer.forward({1.0, 2.0, 3.0});
    EXPECT_EQ(out.size(), 2u);
}

TEST(DenseLayerTest, BackwardInputGradSize) {
    DenseLayer layer(3, 2, 42);
    layer.forward({1.0, 2.0, 3.0});
    auto grad = layer.backward({0.1, 0.2}, 0.01);
    EXPECT_EQ(grad.size(), 3u);
}

// ── Activation tests ─────────────────────────────────────────────────────────

TEST(ActivationTest, ReLUPositive) {
    ReLU relu;
    EXPECT_DOUBLE_EQ(relu.activate(2.0), 2.0);
    EXPECT_DOUBLE_EQ(relu.derivative(2.0), 1.0);
}

TEST(ActivationTest, ReLUNegative) {
    ReLU relu;
    EXPECT_DOUBLE_EQ(relu.activate(-3.0), 0.0);
    EXPECT_DOUBLE_EQ(relu.derivative(-3.0), 0.0);
}

TEST(ActivationTest, SigmoidMidpoint) {
    Sigmoid sig;
    EXPECT_NEAR(sig.activate(0.0), 0.5, 1e-9);
}

TEST(ActivationTest, SigmoidMonotonic) {
    Sigmoid sig;
    EXPECT_GT(sig.activate(1.0), sig.activate(0.0));
    EXPECT_GT(sig.activate(0.0), sig.activate(-1.0));
}

TEST(ActivationTest, TanhRange) {
    Tanh tanh_act;
    EXPECT_NEAR(tanh_act.activate(0.0), 0.0, 1e-9);
    EXPECT_GT(tanh_act.activate(1.0), 0.0);
    EXPECT_LT(tanh_act.activate(-1.0), 0.0);
}

// ── Loss tests ───────────────────────────────────────────────────────────────

TEST(LossTest, MSEPerfect) {
    MSE mse;
    std::vector<double> y = {1.0, 0.0, 1.0};
    EXPECT_NEAR(mse.compute(y, y), 0.0, 1e-9);
}

TEST(LossTest, MSESymmetric) {
    MSE mse;
    std::vector<double> y = {1.0};
    std::vector<double> yh = {0.5};
    EXPECT_NEAR(mse.compute(y, yh), 0.25, 1e-9);
}

TEST(LossTest, MSEGradientSize) {
    MSE mse;
    std::vector<double> y = {1.0, 0.0};
    std::vector<double> yh = {0.8, 0.3};
    auto g = mse.gradient(y, yh);
    EXPECT_EQ(g.size(), 2u);
}

// ── NeuralNet integration tests ───────────────────────────────────────────────

TEST(NeuralNetTest, ForwardOutputSize) {
    NeuralNet nn(std::make_unique<MSE>());
    nn.addLayer(std::make_unique<DenseLayer>(2, 4, 42));
    nn.addLayer(std::make_unique<DenseLayer>(4, 1, 43));
    auto out = nn.forward({0.5, 0.2});
    EXPECT_EQ(out.size(), 1u);
}

TEST(NeuralNetTest, TrainReturnsLoss) {
    NeuralNet nn(std::make_unique<MSE>());
    nn.addLayer(std::make_unique<DenseLayer>(2, 4, 42));
    nn.addLayer(std::make_unique<DenseLayer>(4, 1, 43));
    double loss = nn.train({0.5, 0.2}, {1.0}, 0.01);
    EXPECT_GE(loss, 0.0);
}

TEST(NeuralNetTest, TrainReducesLossOverTime) {
    NeuralNet nn(std::make_unique<MSE>());
    nn.addLayer(std::make_unique<DenseLayer>(2, 4, 42));
    nn.addLayer(std::make_unique<DenseLayer>(4, 1, 43));

    double first_loss = nn.train({0.5, 0.2}, {1.0}, 0.05);
    double last_loss = first_loss;
    for (int i = 0; i < 200; ++i)
        last_loss = nn.train({0.5, 0.2}, {1.0}, 0.05);

    EXPECT_LT(last_loss, first_loss);
}

TEST(NeuralNetTest, MultiSampleTraining) {
    NeuralNet nn(std::make_unique<MSE>());
    nn.addLayer(std::make_unique<DenseLayer>(2, 4, 42));
    nn.addLayer(std::make_unique<DenseLayer>(4, 1, 43));

    std::vector<std::vector<double>> X = {{0.1, 0.2}, {0.8, 0.9}};
    std::vector<std::vector<double>> Y = {{0.0}, {1.0}};

    double total_loss = 0.0;
    for (int epoch = 0; epoch < 300; ++epoch) {
        total_loss = 0.0;
        for (size_t i = 0; i < X.size(); ++i)
            total_loss += nn.train(X[i], Y[i], 0.05);
    }
    // After 300 epochs on 2 linearly separable samples, loss should be small
    EXPECT_LT(total_loss / static_cast<double>(X.size()), 0.1);
}
