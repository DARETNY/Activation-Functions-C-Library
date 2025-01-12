#ifndef ACTIVATION_FACTORY_H
#define ACTIVATION_FACTORY_H

#include <memory>
#include "../interfaces/i_activation.h"
#include "../interfaces/i_vector_activation.h"
#include "../functions/relu.h"
#include "../functions/sigmoid.h"
#include "../functions/tanh.h"
#include "../functions/softmax.h"
#include "../functions/elu.h"
#include "../functions/leaky_relu.h"
#include "../functions/selu.h"
#include "../functions/swish.h"

namespace activation {

struct ActivationFunctionFactory {
    enum Type {
        RELU,
        SIGMOID,
        TANH,
        LEAKY_RELU,
        SWISH,
        SELU_TYPE
    };

    static std::unique_ptr<IActivationFunction> createActivation(Type type) {
        switch (type) {
            case RELU:        return std::make_unique<ReLU>();
            case SIGMOID:     return std::make_unique<Sigmoid>();
            case TANH:        return std::make_unique<Tanh>();
            case LEAKY_RELU:  return std::make_unique<LeakyReLU>();
            case SWISH:       return std::make_unique<Swish>();
            case SELU_TYPE:   return std::make_unique<SELU>();
            default:          throw std::runtime_error("Invalid activation function type: No activation function was chosen");
        }
    }

    static std::unique_ptr<IVectorActivationFunction> createVectorActivation() {
        return std::make_unique<Softmax>();
    }
};

} // namespace activation
#endif