#ifndef ACTIVATION_I_VECTOR_ACTIVATION_H
#define ACTIVATION_I_VECTOR_ACTIVATION_H

#include <string>
#include <vector>

using namespace std;

namespace activation {

struct IVectorActivationFunction {
    virtual ~IVectorActivationFunction() = default;
    virtual double compute(const vector<double>& x, int index) const = 0;
    virtual string getName() const = 0;
};

} // namespace activation
#endif 