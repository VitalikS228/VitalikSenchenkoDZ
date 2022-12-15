// 13.11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    //вводимо строку
    string line;
    cout << "Enter string:";
    getline(cin, line);

    //вводимо символ для видалення
    cout << "Enter char for delete : " ;
    char ch;

    ch = _getch();

    cout << ch << endl;

    string temp = "";

    //перевіряємо чи є символ у строці
    for (int i = 0; i < line.size(); i++) {
        //якщо не він то записуємо у рехультуючу стрічку
        if (line[i] != ch)
            temp += line[i];
    }

    //виводимо результат
    cout << "Line " << endl;
    cout << line << endl;

    line = temp;
    
    cout << "Line without char" << endl;
    cout << line << endl;
    

}
