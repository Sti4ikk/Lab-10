#include <iostream>
#include <cmath>
#include <functional>
#include <Windows.h>

double bisectionMethod(std::function<double(double)> equation, double a, double b, double epsilon);
double equation1(double x);
double equation2(double x);
double equation3(double x);
double equation4(double x);


int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a = 1.5;
    double b = 4.5;
    double epsilon = 0.0001;

    std::cout << "Уравнение 1, корень: " << bisectionMethod(equation1, a, b, epsilon) << std::endl;
    std::cout << "Уравнение 2, корень: " << bisectionMethod(equation2, a, b, epsilon) << std::endl;
    std::cout << "Уравнение 3, корень: " << bisectionMethod(equation3, a, b, epsilon) << std::endl;
    std::cout << "Уравнение 4, корень: " << bisectionMethod(equation4, a, b, epsilon) << std::endl;

    return 0;
}


double bisectionMethod(std::function<double(double)> equation, double a, double b, double epsilon)
{
    double c;
    while ((b - a) >= epsilon)
    {
        c = (a + b) / 2.0;

        // Проверяем, если корень найден
        if (equation(c) == 0.0)
            return c;

        // Делаем выбор интервала для следующей итерации
        if (equation(c) * equation(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

// Функции, задающие уравнения
double equation1(double x)
{
    return 3 * x * x - 150 * std::sin(x);
}

double equation2(double x)
{
    return std::exp(x / 2) - x * x * x + 50;
}

double equation3(double x)
{
    return x * x * x - x * x - 50;
}

double equation4(double x)
{
    return 3 * x - x * x;
}
