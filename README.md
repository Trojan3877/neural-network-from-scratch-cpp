# neural-network-from-scratch-cpp
A feedforward neural network built from scratch in C++ with CSV-based training, backpropagation, modular architecture, quantifiable metrics, and fully documented structure for capstone and Big Tech readiness.
# NeuralNetCPP (Expanded Version)

This project builds a simple fully-connected neural network from scratch in C++ using forward propagation and modular architecture.

---

## 🔧 Files

- `main.cpp`: Entry point using a 3-4-1 neural network.
- `utils.h / utils.cpp`: Activation functions and helpers.
- `neural_network.h / neural_network.cpp`: Forward pass logic with layers, weights, and biases.

---

## 🛠️ Build Instructions

```bash
g++ main.cpp neural_network.cpp utils.cpp -o neural_net
./neural_net
