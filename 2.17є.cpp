// 2.17є.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>

using namespace std;

//функція
double sigmoid(double x) {
    return pow(1 + pow(M_E, -1 * x), -1);
}

//похідна
double sigmoid_derivative(double x) {
    return pow(M_E, -1 * x)/pow((1 + pow(M_E, -1 * x)),2);
}

//основна програма
int main()
{
    double x;
    cout << "Enter x = ";
    cin >> x;
    cout << "f(x) = " << sigmoid(x) << endl;
    cout << "g(x) = " << sigmoid_derivative(x) << endl;
}
