// 5.18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include <string>

using namespace std;

//рекурсивна функція 
string tens(int i,int k) {
    string str = "";
    if (i == k) {
        return std::to_string((int)pow(10,i));
    }
    else {
        int ten = (int)pow(10, i);
        i++;
        return std::to_string(ten) + tens(i, k);
    }
}

//послідовність чисел
string digits(int i, int k) {
    string str = "";
    if (i == k) {
        return std::to_string(i);
    }
    else {
        int digit = i;
        i++;
        return std::to_string(digit) + digits(i, k);
    }
}

//послідовність квадратів
string pows(int i, int k) {
    string str = "";
    if (i == k) {
        return std::to_string((int)pow(i,2));
    }
    else {
        int digit = pow(i,2);
        i++;
        return std::to_string(digit) + pows(i, k);
    }
}
//фібоначі
int fibonacci(int number)
{
    string str = "";
    if (number == 0) {
        return 0; // базовый случай (условие завершения)
    }
        
    if (number == 1) {
        return 1; // базовый случай (условие завершения)
    }
    
    return  fibonacci(number - 1) + fibonacci(number - 2);;
}


//основна програма

int main()
{
    cout << tens(0, 10) << endl;
    cout << digits(1, 10) << endl;
    cout << pows(1, 10) << endl;
    for (int count = 0; count < 13; ++count)
        cout << fibonacci(count);
    cout << endl;
}
