#ifndef ACTIVATION_FACTORY_H
#define ACTIVATION_FACTORY_H

#include <memory>
#include "../interfaces/i_activation.h"
#include "../interfaces/i_vector_activation.h"
#include "../functions/relu.h"
#include "../functions/sigmoid.h"
#include "../functions/tanh.h"
#include "../functions/softmax.h"

using namespace std;

namespace activation {

struct ActivationFunctionFactory {
    enum Type {
        RELU,
        SIGMOID,
        TANH,
        SOFTMAX
    };

    static unique_ptr<IActivationFunction> createActivation(Type type) {
        switch (type) {
            case RELU:    return unique_ptr<IActivationFunction>(new ReLU());
            case SIGMOID: return unique_ptr<IActivationFunction>(new Sigmoid());
            case TANH:    return unique_ptr<IActivationFunction>(new Tanh());
            default:      return unique_ptr<IActivationFunction>(new ReLU());
        }
    }

    static unique_ptr<IVectorActivationFunction> createVectorActivation(Type type) {
        if (type == SOFTMAX) {
            return unique_ptr<IVectorActivationFunction>(new Softmax());
        }
        return nullptr;
    }
};

} // namespace activation
#endif 