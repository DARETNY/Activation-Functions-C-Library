#ifndef ACTIVATION_TANH_H
#define ACTIVATION_TANH_H

#include <cmath>
#include "../interfaces/i_activation.h"

namespace activation {

struct Tanh : public IActivationFunction {
    double compute(double x) const override {
        return std::tanh(x);
    }

    std::string getName() const override {
        return "Tanh";
    }
};

} // namespace activation
#endif 