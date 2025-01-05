#ifndef ACTIVATION_LEAKY_RELU_H
#define ACTIVATION_LEAKY_RELU_H

#include "../interfaces/i_activation.h"

namespace activation {

struct LeakyReLU : public IActivationFunction {
    LeakyReLU(double alpha = 0.01) : alpha_(alpha) {}
    
    double compute(double x) const override {
        return x > 0 ? x : alpha_ * x;
    }
    
    string getName() const override {
        return "LeakyReLU";
    }

    double alpha_;
};

} // namespace activation
#endif 