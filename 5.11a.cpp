// 5.11a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>

using namespace std;

//рекурсивна функція 
double s(double a0, double a1, int k, int n) {
    //наступний елемент
    double ak = a1 + k * a0;
    //кінець рекурсії
    if (k == n){
        return pow(2, k) * a1;
    }
    //коли к =1
    else if (k == 1) {
        k++;
        return pow(2, k) * a0 + s(0, 1, k, n);
    }
    //коли к = 2
    else if (k == 2) {
        k++;
        return pow(2, k) * a1 + s(0, 1, k, n);
    }
    //інщі випадки
    else {
        k++;
        return pow(2, k) * a1 + s(a1, ak, k, n);
    }
}

//основна програма
int main()
{
    int k = 1;
    int n;
    cout << "Enter N = ";
    cin >> n;
    cout << "Sum = " << s(0,1,k,n)<< endl;
}
