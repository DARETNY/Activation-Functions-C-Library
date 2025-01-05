#ifndef ACTIVATION_SWISH_H
#define ACTIVATION_SWISH_H

#include "../interfaces/i_activation.h"
#include <cmath>

namespace activation {

struct Swish : public IActivationFunction {
    Swish(double beta = 1.0) : beta_(beta) {}
    
    double compute(double x) const override {
        return x / (1.0 + std::exp(-beta_ * x));
    }
    
    string getName() const override {
        return "Swish";
    }

    double beta_;
};

} // namespace activation
#endif 