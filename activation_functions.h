#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <string>  // std::string için
#include <vector>  // std::vector için
#include <memory>  // std::unique_ptr için
#include <cmath>   // matematiksel fonksiyonlar için

namespace activation
{
    // Temel aktivasyon fonksiyonu arayüzü
    struct IActivationFunction
    {
        virtual ~IActivationFunction() = default;
        virtual double compute(double x) const = 0;
        virtual std::string getName() const = 0;
    };

    // Vektör tabanlı aktivasyon fonksiyonu arayüzü
    struct IVectorActivationFunction
    {
        virtual ~IVectorActivationFunction() = default;
        virtual double compute(const std::vector<double> &x, int index) const = 0;
        virtual std::string getName() const = 0;
    };

    // Konkret aktivasyon fonksiyonları
    struct ReLU : public IActivationFunction
    {
        double compute(double x) const override
        {
            return std::max(0.0, x);
        }

        std::string getName() const override
        {
            return "ReLU";
        }
    };

    struct Sigmoid : public IActivationFunction
    {
        double compute(double x) const override
        {
            return 1.0 / (1.0 + std::exp(-x));
        }

        std::string getName() const override
        {
            return "Sigmoid";
        }
    };

    struct Tanh : public IActivationFunction
    {
        double compute(double x) const override
        {
            return std::tanh(x);
        }

        std::string getName() const override
        {
            return "Tanh";
        }
    };

    struct Softmax : public IVectorActivationFunction
    {
        double compute(const std::vector<double> &x, int index) const override
        {
            double exp_sum = 0.0;
            for (const double &val : x)
            {
                exp_sum += std::exp(val);
            }
            return std::exp(x[index]) / exp_sum;
        }

        std::string getName() const override
        {
            return "Softmax";
        }
    };

    // Factory sınıfı
    struct ActivationFunctionFactory
    {
        enum Type
        {
            RELU,
            SIGMOID,
            TANH,
            SOFTMAX
        };

        static std::unique_ptr<IActivationFunction> createActivation(Type type)
        {
            switch (type)
            {
            case RELU:
                return std::unique_ptr<IActivationFunction>(new ReLU());
            case SIGMOID:
                return std::unique_ptr<IActivationFunction>(new Sigmoid());
            case TANH:
                return std::unique_ptr<IActivationFunction>(new Tanh());
            default:
                return std::unique_ptr<IActivationFunction>(new ReLU());
            }
        }

        static std::unique_ptr<IVectorActivationFunction> createVectorActivation(Type type)
        {
            if (type == SOFTMAX)
            {
                return std::unique_ptr<IVectorActivationFunction>(new Softmax());
            }
            return nullptr;
        }
    };

} // namespace activation

#endif // ACTIVATION_FUNCTIONS_H