#include <iostream>
#include <iomanip>
#include <random>
#include "activation_functions.h"

using namespace activation;

class ActivationTester
{
private:
    std::vector<double> generateRandomData(int count, double min, double max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);

        std::vector<double> data;
        for (int i = 0; i < count; i++)
        {
            data.push_back(dis(gen));
        }
        return data;
    }

public:
    void testScalarActivations(const std::vector<double> &testData)
    {
        auto relu = ActivationFunctionFactory::createActivation(ActivationFunctionFactory::RELU);
        auto sigmoid = ActivationFunctionFactory::createActivation(ActivationFunctionFactory::SIGMOID);
        auto tanh = ActivationFunctionFactory::createActivation(ActivationFunctionFactory::TANH);

        std::cout << "x\t\t" << relu->getName() << "\t\t"
                  << sigmoid->getName() << "\t\t"
                  << tanh->getName() << std::endl;
        std::cout << "--------------------------------------------------------" << std::endl;

        for (double x : testData)
        {
            std::cout << std::fixed << std::setprecision(4)
                      << x << "\t\t"
                      << relu->compute(x) << "\t\t"
                      << sigmoid->compute(x) << "\t\t"
                      << tanh->compute(x) << std::endl;
        }
    }

    void testVectorActivations(const std::vector<double> &testData)
    {
        auto softmax = ActivationFunctionFactory::createVectorActivation(ActivationFunctionFactory::SOFTMAX);

        std::cout << "\n"
                  << softmax->getName() << " değerleri:" << std::endl;
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "Girdi vektörü: ";
        for (double x : testData)
        {
            std::cout << x << "||";
        }
        std::cout << std::endl
                  << std::endl;

        for (size_t i = 0; i < testData.size(); i++)
        {
            double probability = softmax->compute(testData, i);
            std::cout << "P(x" << i << ") = "
                      << std::fixed << std::setprecision(2)
                      << probability * 100.0 << "%" << std::endl;
        }
    }

    void runTests()
    {
        auto scalarTestData = generateRandomData(10, -5.0, 5.0);
        auto vectorTestData = generateRandomData(5, -5.0, 5.0);

        testScalarActivations(scalarTestData);
        testVectorActivations(vectorTestData);
    }
};

int main()
{
    ActivationTester tester;
    tester.runTests();
    return 0;
}
