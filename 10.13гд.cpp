// 10.13гд.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>

using namespace std;

//робітник
struct Employee {
    string lastName;
    string firstName;
    int year;
    int month;
    int day;
};
//основна програма
int main()
{

    system("chcp 1251");
    //масив робітників
    const int n = 4;
    Employee employees[n];

    //заповнення
    employees[0].lastName = "Іванов";
    employees[0].firstName = "Олег";
    employees[0].year = 1980;
    employees[0].month= 10;
    employees[0].day = 12;

    employees[1].lastName = "Степанов";
    employees[1].firstName = "Микола";
    employees[1].year = 1975;
    employees[1].month = 1;
    employees[1].day = 20;

    employees[2].lastName = "Зеленскьий";
    employees[2].firstName = "Володимир";
    employees[2].year = 1972;
    employees[2].month = 9;
    employees[2].day = 21;

    employees[3].lastName = "Січкорез";
    employees[3].firstName = "Віолета";
    employees[3].year = 1995;
    employees[3].month = 8;
    employees[3].day = 23;

    //поточний рік
    int y = 2022;
    int m = 12;
    int d = 1;

    int avg = 0;
    int max = 0;
    int indexMax = 0;

    //вивід
    for (int i = 0; i < n; i++) {
        
        int old = y - employees[i].year;
        if (m > employees[i].month)
            old - 1;
        if (m > employees[i].month && d < employees[i].day)
            old - 1;
        if (old > max) {
            max = old;
            indexMax = i;
        }
        avg += old;
        
        cout << employees[i].lastName << endl;
        cout << employees[i].firstName << endl;
        cout << employees[i].year << endl;
        cout << employees[i].month << endl;
        cout << employees[i].day << endl;
        cout << old << endl;
        cout << "--------------------" << endl;
    }
    


    //виводимо найстарышого працівника
   
    avg = avg / n;

    cout << "Oldest employee" << endl;

    cout << employees[indexMax].lastName << endl;
    cout << employees[indexMax].firstName << endl;
    cout << employees[indexMax].year << endl;
    cout << employees[indexMax].month << endl;
    cout << employees[indexMax].day << endl;

    //виводимо працівників вік якиз меньше за середній

    cout << "AVG = " << avg << endl;
    cout << "Employees age less than avg" << endl;

    for (int i = 0; i < n; i++) {
        int old = y - employees[i].year;
        if (m > employees[i].month)
            old - 1;
        if (m > employees[i].month && d < employees[i].day)
            old - 1;
        if (old < avg) {
            cout << employees[i].lastName << endl;
            cout << employees[i].firstName << endl;
            cout << employees[i].year << endl;
            cout << employees[i].month << endl;
            cout << employees[i].day << endl;
            cout << old << endl;
            cout << "--------------------" << endl;
        }
    }


}
