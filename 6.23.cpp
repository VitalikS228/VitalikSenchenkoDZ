// 6.23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include <string>

using namespace std;

//функція підрахунку нулів
int num_of_zero(int num) {
    unsigned int unum = (unsigned int)num;
    int count=0;
    int i;

    //ідем по всім бутам
    for (i = 0; i < 32; ++i) {
        //якщо зустріли 0 то збільшуємо каунтер
        if (!(unum & 1)) ++count;
        unum >>= 1;
    }
    //повертаємо результат
    return count;
}

//основна програма
int main()
{
    int d;
    cout << "Enter digit = ";
    cin >> d;
    cout << "count of zeroes = " << num_of_zero(d)<<endl;
}
