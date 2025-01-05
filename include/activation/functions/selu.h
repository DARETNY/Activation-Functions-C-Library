#ifndef ACTIVATION_SELU_H
#define ACTIVATION_SELU_H

#include "../interfaces/i_activation.h"
#include <cmath>

namespace activation {

struct SELU : public IActivationFunction {
    SELU() : alpha_(1.67326), scale_(1.05070) {}
    
    double compute(double x) const override {
        return scale_ * (x > 0 ? x : alpha_ * (std::exp(x) - 1));
    }
    
    string getName() const override {
        return "SELU";
    }

    const double alpha_;
    const double scale_;
};

} // namespace activation
#endif 