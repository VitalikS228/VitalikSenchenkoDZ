// 2.13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

//функція розразунку об'єму
double volume(double r, double R) {
    //результат
    return 2 * atan(1) * 4 * pow(r, 2) * pow(R, 2);
}

//основна програма
int main()
{
    double r, R;
    cout << "Enter r = ";
    cin >> r;
    cout << "Enter R = ";
    cin >> R;
    cout << "Volume = " << volume(r, R);
}
