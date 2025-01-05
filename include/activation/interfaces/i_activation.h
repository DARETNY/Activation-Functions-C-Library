#ifndef ACTIVATION_I_ACTIVATION_H
#define ACTIVATION_I_ACTIVATION_H

#include <string>

using namespace std;

namespace activation {

struct IActivationFunction {
    virtual ~IActivationFunction() = default;
    virtual double compute(double x) const = 0;
    virtual string getName() const = 0;
};

} // namespace activation
#endif 