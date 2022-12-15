// 11.12a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>


using namespace std;


//структура іграшки
struct Toy {
    string toyname;
    int price;
    int age;
};



//основна програма
int main()
{
    //вектор іграшок
    vector<Toy> toys;
    string line;

    //читаємо файл
    ifstream MyReadFile("toys.txt");

    //заполюємо структуру
    while (getline(MyReadFile, line)) {
        Toy toy;
        toy.toyname = line;
        getline(MyReadFile, line);
        toy.price = stoi(line);
        getline(MyReadFile, line);
        toy.age = stoi(line);
        //додаємо структру у вектор
        toys.push_back(toy);
    }

    MyReadFile.close();

    //виводимо усі зчитані іграшки з вектору
    for (int i = 0; i < toys.size(); i++) {
        cout << toys.at(i).toyname << endl;
        cout << toys.at(i).price<< endl;
        cout << toys.at(i).age << endl;
        cout << "--------------" << endl;
    }

    //ввдимо ціну
    int price;
    cout << "Enter price : ";
    cin >> price;

    // Create and open a text file
    ofstream MyFile("result.txt");

    //шукаємо іграшки,що деевші за нащу ціну, та віком до 5 років 
    cout << "TOYS by price and age:" << endl;

    for (int i = 0; i < toys.size(); i++) {
        //ось тут наша умова
        if (price > toys.at(i).price && toys.at(i).age <= 5) {
            cout << toys.at(i).toyname << endl;
            cout << toys.at(i).price << endl;
            cout << toys.at(i).age << endl;
            cout << "--------------" << endl;
            // Пишемо в файл
            MyFile << toys.at(i).toyname;
            MyFile << "\n";
        }
    }

    MyFile.close();

}
