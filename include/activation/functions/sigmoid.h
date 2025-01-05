#ifndef ACTIVATION_SIGMOID_H
#define ACTIVATION_SIGMOID_H

#include <cmath>
#include "../interfaces/i_activation.h"

namespace activation {

struct Sigmoid : public IActivationFunction {
    double compute(double x) const override {
        return 1.0 / (1.0 + std::exp(-x));
    }

    std::string getName() const override {
        return "Sigmoid";
    }
};

} // namespace activation
#endif 