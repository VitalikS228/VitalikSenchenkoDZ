// 11.9а.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

    int countPositive = 0;
    int countNegative = 0;

    //заполюємо структуру
    while (getline(MyReadFile, line)) {
        if (stoi(line) > 0) {
            countPositive++;
        }
        else {
            countNegative++;
        }
        digits.push_back(stoi(line));
    }

    MyReadFile.close();

    cout << "DIGITS" << endl;
    //виводимо усі зчитані іграшки з вектору
    for (int i = 0; i < digits.size(); i++) {
        cout << digits.at(i) << " ";
    }

    cout << endl;

    if (countNegative != countPositive) {
        cout << "Count of positive != count of negative!!!" << endl;
        cout << "Finishing..." << endl;
    }
    else {

        //записуємо в проміжковий файл лише додатні числа.

        ofstream MyFile("H.txt");

        for (int i = 0; i < digits.size(); i++) {
            if (digits.at(i) > 0)
            {
                MyFile << digits.at(i);
                MyFile << "\n";
            }
        }

        MyFile.close();

        //створюємо файл куди запишемо результат
        ofstream MyFile2("G.txt");
        ifstream MyReadFile2("H.txt");

        for (int i = 0; i < digits.size(); i++) {
            if (digits.at(i) < 0)
            {
                MyFile2 << digits.at(i);
                MyFile2 << "\n";
                getline(MyReadFile2, line);
                MyFile2 << line;
                MyFile2 << "\n";
            }
        }

        MyFile2.close();
        MyReadFile2.close();


    }
}