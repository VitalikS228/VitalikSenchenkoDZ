// 5.16є.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>

using namespace std;

//рекурсивна функція 
double y(int k, double x,double eps) {
    double s1 = pow(-1, k) * pow(x, k);
    k++;
    double s2 = pow(-1, k) * pow(x, k);
    if (s2 - s1 < eps)
        return (s2 + s1);
    else {
        k++;
        return s2 + s1 + y(k, x, eps);
    }
        
}

//основна програма
int main()
{
    double eps = 0.001;
    int k = 0;
    double x;
    
    cout << "Enter X = ";
    cin >> x;
    
    cout << "y = " << y(k, x,eps) << endl;
    cout << "y = " << 1.0 / (1.0 + x) << endl;

}