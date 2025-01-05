#ifndef ACTIVATION_RELU_H
#define ACTIVATION_RELU_H

#include <cmath>
#include "../interfaces/i_activation.h"

namespace activation {

struct ReLU : public IActivationFunction {
    double compute(double x) const override {
        return std::max(0.0, x);
    }

    std::string getName() const override {
        return "ReLU";
    }
};

} // namespace activation
#endif 