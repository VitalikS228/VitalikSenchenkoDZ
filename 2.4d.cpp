// 2.4d.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

//функція обрахунку результату
double y(double x) {
    double result = 0;
    int i = 0;
    //для найменшої кількості операцій робимо це в циклі
    for (int i = 0; i <= 4; i++) {
        result += pow(2, i) * pow(x, i);
    }
    //повертаємо результат
    return result;
}

//основна програма
int main()
{
    double x;
    cout << "Enter x = ";
    cin >> x;
    cout << "y = " << y(x) << endl;
}

