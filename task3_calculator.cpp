#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

inline double square(double x) {
    return x * x;
}

double power(double base, int exponent = 2);

double calc(double a, double b, char op);
double calc(int a, int b, char op);

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

double calc(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0.0) {
            std::cout << "Error: divide by zero" << std::endl;
            return std::nan("");
        }
        return a / b;
    default:
        std::cout << "Error: unknown operator" << std::endl;
        return std::nan("");
    }
}

double calc(int a, int b, char op) {
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

int main() {
    double a = 0.0;
    double b = 0.0;
    char op = '+';
    if (!(std::cin >> a >> b >> op)) {
        return 0;
    }

    std::cout << "square(" << std::defaultfloat << a << ") = "
              << std::fixed << std::setprecision(2) << square(a) << std::endl;
    std::cout << "power(" << std::defaultfloat << a << ",3) = "
              << std::fixed << std::setprecision(2) << power(a, 3) << std::endl;

    bool bothIntegral = (std::floor(a) == a) && (std::floor(b) == b);
    double result = bothIntegral
        ? calc(static_cast<int>(a), static_cast<int>(b), op)
        : calc(a, b, op);

    if (!std::isnan(result)) {
        std::cout << std::defaultfloat << a << ' ' << op << ' ' << b << " = "
                  << std::fixed << std::setprecision(2) << result << std::endl;
    }
    return 0;
}
