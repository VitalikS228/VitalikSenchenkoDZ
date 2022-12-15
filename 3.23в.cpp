// 3.23в.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>

using namespace std;

//функція
double leakyReLu(double x, double a) {
    if (x < 0) {
        return a * x;
    }
    else {
        return 0;
    }
}

//похідна
double leakyReLu_derivative(double x, double a) {
    if (x < 0) {
        return a;
    }
    else {
        return 0;
    }
}

//основна програма
int main()
{
    double x,a;
    cout << "Enter x = ";
    cin >> x;
    cout << "Enter a = ";
    cin >> a;

    cout << "f(x) =" << leakyReLu(x, a) << endl;
    cout << "g(x) =" << leakyReLu_derivative(x, a) << endl;

}
