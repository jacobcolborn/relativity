#include <iostream>
#include <cmath>
#include <functional>

// Function to compute the numerical derivative
double numericalDerivative(std::function<double(double)> func, double x, double h = 1e-5) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

// Example function: f(x) = x^2
double exampleFunction(double x) {
    return x * x;
}

int derivative() {
    double x = 2.0; // Point at which to compute the derivative
    double h = 1e-5; // Step size

    // Using a lambda function for the example function
    auto func = [](double x) { return x * x; };

    double derivative = numericalDerivative(func, x, h);

    std::cout << "The derivative of f(x) = x^2 at x = " << x << " is approximately " << derivative << std::endl;

    return 0;
}
