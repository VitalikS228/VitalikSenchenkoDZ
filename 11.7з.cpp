// 11.7з.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

int main()
{
    
    int max = -99999;
    int min = 99999;

    string line;

    ifstream MyReadFile("digits.txt");

    while (getline(MyReadFile, line)) {
        cout << line << endl;
        if (stoi(line) > max) {
            max = stoi(line);
        }
        if (stoi(line) < min) {
            min = stoi(line);
        }
    }
    
    MyReadFile.close();

    cout << "MIN : " << min << endl;
    cout << "MAX : " << max << endl;

    cout << "SUM : " << min + max << endl;

}
