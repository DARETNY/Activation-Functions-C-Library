# Activation Functions Library

A modern C++ library containing essential activation functions used in neural networks.

## 🎯 Overview
This library provides commonly used activation functions in a modular and extensible way. It features:
- Object-oriented implementation of activation functions
- Easy integration with existing projects
- Debug support with Icecream library

## 📚 Supported Functions

### 1. Sigmoid
- Maps values to [0,1] range
- $`f(x) = 1 / (1 + e^{-x})`$

### 2. ReLU (Rectified Linear Unit)
- Zeros out negative values
- $`f(x) = max(0, x)`$

### 3. Tanh
- Maps values to [-1,1] range
- $`f(x) = (e^x - e^{-x}) / (e^x + e^{-x})`$

### 4. Softmax
- Takes vector input
- Produces probability distribution
- $`softmax(x_i) = \frac{e^{x_i}}{\sum_{j=1}^{n} e^{x_j}}`$

## 🚀 Quick Start

```cpp
#include "activation/factory/activation_factory.h"

using namespace activation;

int main() {
    // Create activation function
    auto activation = ActivationFunctionFactory::createActivation(
        ActivationFunctionFactory::Type::SIGMOID);
    
    // Use the function
    double result = activation->compute(1.0);
    return 0;
}
```

## 📦 Installation

```bash
git clone [repo-url]
cd activation-lib
mkdir build && cd build
cmake ..
make
```

## 🛠️ Requirements
- C++17 compiler
- CMake 3.10 or higher

## 📄 License
MIT License

---
For more details and examples, check the `examples/` directory.
