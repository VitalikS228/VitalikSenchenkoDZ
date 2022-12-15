// 4.0.27.0є.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>

using namespace std;

//функція
double pi(double eps) {
    
    int k = 0;
    double r1 = 0.0;
    double r2 = 0.0;
    
    do {
        r1 = r2 + (pow(-1.0, k) / pow(16.0, k)) * (8.0 / (8.0 * (double)k + 2.0) + 4.0 / (8.0 * (double)k + 3.0) + 4.0 / (8.0 * (double)k + 4.0) - 1 / (8.0 * (double)k + 7.0));
        k++;
        r2 = r1 + (pow(-1.0, k) / pow(16.0, k)) * (8.0 / (8.0 * (double)k + 2.0) + 4.0 / (8.0 * (double)k + 3.0) + 4.0 / (8.0 * (double)k + 4.0) - 1 / (8.0 * (double)k + 7.0));
        k++;

    } while ((r1 - r2) > eps);

    
    double PI = (r1 + r2) / 2.0;

    return PI;
}
//основна програма
int main()
{
    double eps = 0.00001;
    cout << "PI = " << pi(eps) << endl;
    cout << "Math PI = " << 2 * M_PI << endl;

}