// 3.17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>

using namespace std;

// пошук перетину двох квадратів 
void FindPoints(int x1, int y1, int x2, int y2,
    int x3, int y3, int x4, int y4)
{
    // нижній лівий кут
    int x5 = max(x1, x3);
    int y5 = max(y1, y3);

    //правий верхній кут
    int x6 = min(x2, x4);
    int y6 = min(y2, y4);

    // немає перетину
    if (x5 > x6 || y5 > y6) {
        cout << "\nNo intersection between squares.";
        return;
    }
    //координати перетину
    cout << ("\nThe squares intersect.\n");
    cout << ("Points of intersection: \n");
    cout << "(" << x5 << ", " << y5 << ") ";
    cout << "(" << x6 << ", " << y6 << ") ";
}

int main()
{
    //координаты квадратов 
    int x1, x2, y1, y2;
    int a1, a2;
    
    cout << ("Please, enter the coordinates.\n");
    cout << ("\nEnter the coordinates x1, y1, and width A for the first square: ");
    cin >> x1 >> y1 >> a1;
    cout << ("\nEnter the coordinates x2, y2, and width A for the second square: ");
    cin >> x2 >> y2 >> a2;

    //пошук точек
    FindPoints(x1, y1, x1+a1, y1+a1, x2, y2, x2+a2, y2+a2);

}
