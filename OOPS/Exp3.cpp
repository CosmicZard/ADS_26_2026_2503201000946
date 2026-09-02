#include <iostream>
using namespace std;

inline int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b = 10)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
double multiply(double a, double b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}
double divide(double a, double b)
{
    return a / b;
}

int main()
{
    cout << "Addition: " << add(20, 10) << endl;
    cout << "Subtraction: " << subtract(20) << endl;
    cout << "Subtraction: " << subtract(20, 5) << endl;
    cout << "Multiplication: " << multiply(5, 4) << endl;
    cout << "Multiplication: " << multiply(5.5, 2.0) << endl;
    cout << "Division: " << divide(20, 5) << endl;
    cout << "Division: " << divide(20.0, 3.0) << endl;
    return 0;
}
