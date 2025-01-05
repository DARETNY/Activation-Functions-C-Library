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
- **Usage**: 
  - Classic activation function for binary classification
  - Output layer of neural networks when probability is needed
  - Smooth gradient, but suffers from vanishing gradient problem
  - Works well in the last layer of binary classification

### 2. ReLU (Rectified Linear Unit)
- Zeros out negative values
- $`f(x) = max(0, x)`$
- **Usage**: 
  - Most popular activation function in deep learning
  - Solves vanishing gradient problem
  - Computationally efficient
  - Sparse activation (helps with feature selection)
  - Default choice for convolutional neural networks and deep learning

### 3. Leaky ReLU
- Allows small negative values
- $`f(x) = x \text{ if } x > 0 \text{ else } \alpha x`$
- Default α = 0.01
- **Usage**: 
  - Addresses "dying ReLU" problem
  - Better gradient flow for negative inputs
  - Helps prevent dead neurons
  - Good for deep networks where ReLU units might die

### 4. ELU (Exponential Linear Unit)
- Smooth alternative to ReLU
- $`f(x) = x \text{ if } x > 0 \text{ else } \alpha(e^x - 1)`$
- Default α = 1.0
- **Usage**: 
  - Smoother gradient flow than ReLU
  - Can produce negative outputs
  - Helps with internal covariate shift
  - Good for deep neural networks
  - Better than ReLU in some cases, but more computationally expensive

### 5. SELU (Scaled Exponential Linear Unit)
- Self-normalizing variant of ELU
- $`f(x) = \lambda x \text{ if } x > 0 \text{ else } \lambda\alpha(e^x - 1)`$
- λ = 1.0507, α = 1.67326
- **Usage**: 
  - Self-normalizing neural networks
  - Automatically normalizes network activations
  - Helps maintain mean and variance
  - Good for deep networks without batch normalization
  - Especially useful in fully-connected networks

### 6. Tanh
- Maps values to [-1,1] range
- $`f(x) = (e^x - e^{-x}) / (e^x + e^{-x})`$
- **Usage**: 
  - Zero-centered output, making it easier for the next layer
  - Often used in recurrent neural networks (RNNs)
  - Better than sigmoid for hidden layers
  - Good for data normalized between -1 and 1

### 7. Softmax
- Takes vector input
- Produces probability distribution
- $`softmax(x_i) = \frac{e^{x_i}}{\sum_{j=1}^{n} e^{x_j}}`$
- **Usage**: 
  - Standard choice for multi-class classification
  - Output layer for probability distribution
  - Ensures outputs sum to 1.0
  - Works well with cross-entropy loss
  - Essential for multi-class neural networks

### 8. Swish
- Self-gated activation function
- $`f(x) = x / (1 + e^{-\beta x})`$
- Default β = 1.0
- **Usage**: 
  - Modern alternative to ReLU
  - Discovered by automated search
  - Sometimes outperforms ReLU in deep networks
  - Non-monotonic function allowing better gradient flow
  - Good for very deep networks (>40 layers)

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
