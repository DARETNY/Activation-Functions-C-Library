#pragma once

#include <string>

namespace activation {
namespace core {

struct IActivationFunction {
    virtual ~IActivationFunction() = default;
    virtual double compute(double x) const = 0;
    virtual std::string getName() const = 0;
};

} // namespace core
} // namespace activation 