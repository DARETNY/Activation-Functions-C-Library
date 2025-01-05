#ifndef ACTIVATION_ELU_H
#define ACTIVATION_ELU_H

#include "../interfaces/i_activation.h"
#include <cmath>

namespace activation {

struct ELU : public IActivationFunction {
    ELU(double alpha = 1.0) : alpha_(alpha) {}
    
    double compute(double x) const override {
        return x > 0 ? x : alpha_ * (std::exp(x) - 1);
    }
    
    string getName() const override {
        return "ELU";
    }

    double alpha_;
};

} // namespace activation
#endif 