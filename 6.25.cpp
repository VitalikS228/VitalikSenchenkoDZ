// 6.25.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include <string>

using namespace std;

//функція підрахунку нулів
bool one_in_the_same_position(int num1, int num2) {
    unsigned int unum1 = (unsigned int)num1;
    unsigned int unum2 = (unsigned int)num2;
    
    int a1[32];
    int a2[32];
    

    //ідем по всім бітам
    for (int i = 0; i < 32; ++i) {
        //якщо зустріли 0 то пишимо в масив 0
        if (!(unum1 & 1)) {
            a1[i] = 0;
        }
        //інакше пишемо 1
        else {
            a1[i] = 1;
        }
        unum1 >>= 1;
    }

    //ідем по всім бітам
    for (int i = 0; i < 32; ++i) {
        //якщо зустріли 0 то пишимо в масив 0
        if (!(unum2 & 1)) {
            a2[i] = 0;
        }
        //інакше пишемо 1
        else {
            a2[i] = 1;
        }
        unum2 >>= 1;
    }

    //ідем по всім бітам
    for (int i = 0; i < 32; ++i) {
        if (a1[i] == a2[i] && a1[i] == 1) {
            return true;
        }
    }

    //повертаємо результат
    return false;
}

//основна програма
int main()
{
    int num1,num2;
    cout << "Enter number 1 = ";
    cin >> num1;
    cout << "Enter number 2 = ";
    cin >> num2;
    cout << "Is 1 in the same postition? " << (one_in_the_same_position(num1,num2) ? "Yes" : "No") << endl;
}
