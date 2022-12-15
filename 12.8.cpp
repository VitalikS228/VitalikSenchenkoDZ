// 12.8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include <fstream> 
#include <vector>


using namespace std;


//основна програма
int main()
{
    //вектор іграшок
    vector<int> digits;
    string line;

    //читаємо файл
    ifstream MyReadFile("F.txt");

    //заполюємо структуру
    while (getline(MyReadFile, line)) {
        digits.push_back(stoi(line));
    }

    MyReadFile.close();

    cout << "DIGITS" << endl;
    //виводимо усі зчитані іграшки з вектору
    for (int i = 0; i < digits.size(); i++) {
        cout << digits.at(i) << " ";
    }

    cout << endl;

 
    //записуємо в проміжковий файл лише додатні числа.

    ofstream MyFile("digits.txt");

    for (int i = 0; i < digits.size(); i++) {
            MyFile << digits.at(i);
            MyFile << " ";
            MyFile << exp(digits.at(i));
            MyFile << "\n";
    }

    MyFile.close();
}