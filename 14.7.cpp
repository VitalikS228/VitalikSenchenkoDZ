// 14.7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;

//основна програма
int main()
{
    //вектор строк
    vector<string> lines;
    string line;

    //читаємо файл
    ifstream MyReadFile("tags.txt");

    while (getline(MyReadFile, line)) {
        lines.push_back(line);
    }

    MyReadFile.close();

    cout << "Lines" << endl;
    //виводимо усі строки
    for (int i = 0; i < lines.size(); i++) {
        cout << lines.at(i) << endl;
    }

    //перевіряємо кожну стрічку
    for (int i = 0; i < lines.size(); i++) {
        int startPosition = -1;
        int endPosition = -1;
        for (int j = 0; j < lines.at(i).size(); j++) {
            if (lines.at(i)[j] == '<') {
                if (startPosition != -1) {
                    cout << "Tag in position " << startPosition << " at line : "<< i << " doesnt have close tag '/>'" << endl;
                    startPosition = j;
                }
                else {
                    startPosition = j;
                }
            }
            if (lines.at(i)[j] == '>') {
                if (lines.at(i)[j - 1] != '/') {
                    cout << "Tag in position " << startPosition << " at line : " << i << " doesnt have close tag '/>'" << endl;
                    startPosition = -1;
                }
                else {
                    cout << "Tag : " << lines.at(i).substr(startPosition+1,j-startPosition-2)<< endl;
                    startPosition = -1;
                    endPosition = -1;
                }
            }
        }
        if (startPosition != -1 && endPosition == -1) {
            cout << "Tag in position " << startPosition << " at line : " << i << " doesnt have close tag '/>'" << endl;
        }
    }
}