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

using namespace std;

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

    static unique_ptr<IActivationFunction> createActivation(Type type) {
        switch (type) {
            case RELU:    return unique_ptr<IActivationFunction>(new ReLU());
            case SIGMOID: return unique_ptr<IActivationFunction>(new Sigmoid());
            case TANH:    return unique_ptr<IActivationFunction>(new Tanh());
            case LEAKY_RELU: return unique_ptr<IActivationFunction>(new LeakyReLU());
            case SWISH:   return unique_ptr<IActivationFunction>(new Swish());
            case SELU_TYPE: return unique_ptr<IActivationFunction>(new SELU());
            default:      throw std::runtime_error("Invalid activation function type: No activation function was chosen");
        }
    }

    static unique_ptr<IVectorActivationFunction> createVectorActivation() {
        return unique_ptr<IVectorActivationFunction>(new Softmax());
    }
};

} // namespace activation
#endif 