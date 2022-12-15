// 4.19a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>

using namespace std;

//функція
double p(int n) {
    double result = 0;
    for (int i = 1; i <= n; i++) {
        result += (1 + 1 / pow(i,2));
    }
    return result;
}
//основна програма
int main()
{
    int n=1;
    //перевірка на те що N > 2
    while (n <= 2) {
        cout << "Enter n = ";
        cin >> n;
    }
    cout << "p = " << p(n) << endl;
}
