#include <iostream>
#include <iomanip>
#include <random>
#include "../include/activation/factory/activation_factory.h"
#include "icecream.hpp"

using namespace std;
using namespace activation;

int main()
{
    IC_CONFIG.prefix("\033[32m", "ic| ", "\033[0m");

    ActivationFunctionFactory::Type function = ActivationFunctionFactory::Type::SIGMOID;
    unique_ptr<IActivationFunction> activation = ActivationFunctionFactory::createActivation(function);
    IC(activation->getName());
    cout << "--------------------------------------------------------" << endl;
    // Test farklı değerler için
    vector<double> test_values = {-2.0, -1.0, -0.5, 0.0, 0.5, 1.0, 2.0};
    for (const auto &val : test_values)
    {
        IC(val, activation->compute(val));
    }

    return 0;
}
