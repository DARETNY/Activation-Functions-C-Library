#ifndef ACTIVATION_SOFTMAX_H
#define ACTIVATION_SOFTMAX_H

#include <cmath>
#include "../interfaces/i_vector_activation.h"

namespace activation {

struct Softmax : public IVectorActivationFunction {
    double compute(const std::vector<double>& x, int index) const override {
        double exp_sum = 0.0;
        for (const double& val : x) {
            exp_sum += std::exp(val);
        }
        return std::exp(x[index]) / exp_sum;
    }

    std::string getName() const override {
        return "Softmax";
    }
};

} // namespace activation
#endif 