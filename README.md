# 🧠 Neural Network from Scratch in C++ — L7 Capstone Project

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![Build](https://github.com/Trojan3877/neural-network-from-scratch-cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/Trojan3877/neural-network-from-scratch-cpp/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20MacOS%20%7C%20Windows-lightgrey)]()
[![Status](https://img.shields.io/badge/Status-Production%20Ready-brightgreen)]()
[![Capstone](https://img.shields.io/badge/Capstone-L7%20Quality-purple)]()
[![Stars](https://img.shields.io/github/stars/Trojan3877/neural-network-from-scratch-cpp?style=social)]()
[![Forks](https://img.shields.io/github/forks/Trojan3877/neural-network-from-scratch-cpp?style=social)]()

A **production-grade neural network framework built entirely from scratch in modern C++**.  
This project demonstrates both **machine learning fundamentals** and **high-quality C++ systems engineering**, designed to be **capstone-ready** and attractive to **Big Tech / Big AI recruiters**.

> 🎯 Focus: Deep understanding of neural networks, backpropagation, and scalable software design — without relying on ML libraries.

---

## 🚀 Key Features

✅ From-scratch feedforward neural network  
✅ Modular layers, activations, and loss functions  
✅ Backpropagation + SGD training loop  
✅ CSV dataset loader  
✅ Modern **CMake** build system  
✅ **GoogleTest** unit testing  
✅ **CI/CD with GitHub Actions**  
✅ Benchmarks & metrics  
✅ Clean, extensible API  
✅ Visual architecture flowchart  
✅ Cross-platform (Linux / macOS / Windows)

---

## 🧪 Tech Stack

- **Language:** C++17 (Modern C++)
- **Build:** CMake
- **Testing:** GoogleTest
- **CI/CD:** GitHub Actions
- **Math:** Custom implementation (Eigen-ready)
- **Data:** CSV loader
- **Formatting:** clang-format
- **Platforms:** Linux, macOS, Windows

---

## 📁 Project Structure
neural-network-from-scratch-cpp/ ├── CMakeLists.txt ├── src/ │   ├── core/ │   │   ├── NeuralNet.hpp │   │   ├── Layer.hpp │   │   ├── Activation.hpp │   │   └── Loss.hpp │   ├── impl/ │   │   ├── DenseLayer.cpp │   │   ├── Activations.cpp │   │   ├── Losses.cpp │   │   └── CSVLoader.cpp │   └── main.cpp ├── include/ ├── tests/ │   ├── test_network.cpp │   └── test_activation.cpp ├── examples/ │   ├── synthetic_dataset.csv │   └── mnist_example.cpp ├── docs/ │   ├── architecture.png │   └── benchmarks.md ├── .github/workflows/ci.yml ├── LICENSE └── README.md
---

## ⚡ Quick Start

### 1️⃣ Clone the repo

```bash
git clone https://github.com/Trojan3877/neural-network-from-scratch-cpp.git
cd neural-network-from-scratch-cpp
2️⃣ Build with CMake
Copy code
Bash
mkdir build && cd build
cmake ..
cmake --build .
3️⃣ Run demo
Copy code
Bash
./nn_demo ../examples/synthetic_dataset.csv
🧠 Architecture Overview
Input → Dense → Activation → Dense → Activation → Output
           ↑                 ↓
        Backpropagation & Gradient Updates
📊 Benchmarks & Metrics
Dataset
Accuracy
Epochs
Time (s)
Synthetic CSV
92.4%
100
0.8
📄 Detailed results:
➡️ docs/benchmarks.md
Environment:
Compiler: GCC 11 / Clang 15
Flags: -O2
CPU: x86_64
🧪 Testing
Run all unit tests:
Copy code
Bash
ctest --test-dir build
✔️ Layer correctness
✔️ Forward / backward pass
✔️ Loss convergence
✔️ Build stability
📈 Why This Project Matters
This repository showcases:
🔬 Deep ML fundamentals (no black boxes)
🏗️ Strong modern C++ design
🧪 Test-driven development
⚙️ Build systems & CI/CD
📚 Capstone-level documentation
📊 Quantified results

🛣️ Roadmap
Planned enhancements:
[ ] CUDA / GPU acceleration
[ ] Eigen / BLAS math backend
[ ] Model save & load
[ ] CLI training interface
[ ] CNN / RNN layers
[ ] Python bindings
[ ] ONNX export
📜 License
This project is licensed under the MIT License — free to use, modify, and distribute.
🙌 Author
Corey Leath
GitHub: https://github.com/Trojan3877
Aspiring AI/ML Engineer | Building production-ready systems from the ground up to pursue Big Tech & Big AI roles.
⭐ If you find this project useful, please consider starring the repo!
