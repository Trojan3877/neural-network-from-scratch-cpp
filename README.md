# 🧠 Neural Network from Scratch in C++  Capstone Project
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![Build](https://github.com/Trojan3877/neural-network-from-scratch-cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/Trojan3877/neural-network-from-scratch-cpp/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)]()
[![Capstone](https://img.shields.io/badge/Capstone-L7%20Quality-purple.svg)]()
[![Status](https://img.shields.io/badge/Status-Production%20Ready-brightgreen.svg)]()
[![Stars](https://img.shields.io/github/stars/Trojan3877/neural-network-from-scratch-cpp.svg?style=social)](https://github.com/Trojan3877/neural-network-from-scratch-cpp/stargazers)
[![Forks](https://img.shields.io/github/forks/Trojan3877/neural-network-from-scratch-cpp.svg?style=social)](https://github.com/Trojan3877/neural-network-from-scratch-cpp/network/members)

A **production-grade neural network framework built entirely from scratch in modern C++**.  
This project demonstrates both **machine learning fundamentals** and **high-quality C++ systems engineering**, designed to be **capstone-ready** and attractive to **Big Tech / Big AI recruiters**.

Focus: Deep understanding of neural networks, backpropagation, and scalable software design — without relying on ML libraries.



 Key Features

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
Design Questions & Reflections
Q: What problem does this project aim to solve?
A: This project implements a neural network from scratch in C++ to deepen my understanding of how core learning algorithms work at a lower level. Rather than relying on high-level frameworks, I wanted to explore the mechanics of forward passes, loss computation, backpropagation, and weight updates in a language close to the hardware.
Q: Why did I choose to build this from scratch instead of using a library?
A: I chose to build it from scratch because frameworks often abstract away the math and control flow that make neural networks effective. Writing the algorithms myself helped me see the underlying mechanics and trade-offs, and C++ gave me a sense of how performance and memory management interact with model logic.
Q: What were the main trade-offs I made?
A: The main trade-off was implementation complexity versus ease of experimentation. Writing everything manually meant slower development and more boilerplate, but it rewarded me with deep, first-principles understanding that I wouldn’t have gotten by using ready-made libraries.
Q: What didn’t work as expected?
A: In early versions, I struggled to get the gradient calculations correct — subtle sign errors and incorrect matrix indexing led to training that didn’t converge. Fixing this forced me to slow down and validate every step, which improved my grasp of backpropagation and numerical stability.
Q: What did I learn from building this project?
A: I learned that many of the behaviors we take for granted in libraries — stable gradients, efficient memory layout, numerical precision — are the result of intentional design choices. Building from scratch clarified both the why and how of deep learning fundamentals.
Q: If I had more time or resources, what would I improve next?
A: I would add better testing for edge cases and integrate simple visualizations to watch how weight updates evolve during training. I’d also explore optimizing the code further, exploring SIMD or parallel computation to see how much performance could be gained.
🙌 Author
Corey Leath
GitHub: https://github.com/Trojan3877
Aspiring AI/ML Engineer | Building production-ready systems from the ground up to pursue Big Tech & Big AI roles.
⭐ If you find this project useful, please consider starring the repo!
