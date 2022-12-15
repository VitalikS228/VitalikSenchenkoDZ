// 16.14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream> 
#include <string>
#include <vector>


using namespace std;

//класс адреси
class Adress {
    //приватні поля
private:
    string city;
    string street;
    int number;
    //конструктор та піблічні методи
public:
    Adress(string city, string street, int number) {
        this->city = city;
        this->street = street;
        this->number = number;
    }
    string getCity() {
        return city;
    }
    string getStreet() {
        return street;
    }
    int getNumber() {
        return number;
    }

    string toString() {
        return city + "\n" + street + "\n";
    }
};

//нащадок від класа Адреса, Міжнародна адреса
class UniversalAddress : public Adress {
    //додаткові поля
private:
    string country;
    string postCode;
    //констркуктор та публічні методи
public:
    UniversalAddress(string city, string street, int number, string country, string postCode) : Adress(city, street, number) {
        this->country = country;
        this->postCode = postCode;
    }
    string getCountry() {
        return country;
    }
    string getPostCode() {
        return postCode;
    }
    string toString() {
        return this->toString() + country + "\n" + postCode + "\n";
    }

};

int main()
{

    //заповдення масивів
    vector<Adress> adresses;
    vector<UniversalAddress> universalAdresses;

    Adress adress1("Odessa", "Deribasivska", 10);
    Adress adress2("Odessa", "Deribasivska", 20);
    Adress adress3("Odessa", "Deribasivska", 30);
    Adress adress4("Odessa", "Deribasivska", 40);
    Adress adress5("Kiev", "Hreschatik", 10);
    Adress adress6("Lviv", "Tarasa Shevchenko", 20);
    Adress adress7("Mikolayiv", "Mazepi", 30);
    Adress adress8("Odessa", "Primorskiy bulvar", 33);

    UniversalAddress universalAdress1("Lviv", "Tarasa Shevchenko", 20,"Ukraine","68420");
    UniversalAddress universalAdress2("Odessa", "Deribasivska", 20, "Ukraine", "68420");
    UniversalAddress universalAdress3("Kiev", "Hreschatik", 10, "Ukraine", "68420");

    adresses.push_back(adress1);
    adresses.push_back(adress2);
    adresses.push_back(adress3);
    adresses.push_back(adress4);
    adresses.push_back(adress5);
    adresses.push_back(adress6);
    adresses.push_back(adress7);
    adresses.push_back(adress8);

    universalAdresses.push_back(universalAdress1);
    universalAdresses.push_back(universalAdress2);
    universalAdresses.push_back(universalAdress3);
    
    //пошук найчастіщого міста
    int count = 0;
    int max = 0;
    string city;


    for (int i = 0; i < universalAdresses.size(); i++) {
        for (int j = 0; j < adresses.size(); j++) {
            if (universalAdresses.at(i).getCity() == adresses.at(j).getCity()) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            city = universalAdresses.at(i).getCity();
        }
        count = 0;
    }

    
    //запис у файл
    ofstream MyFile("cities.txt");

    for (int j = 0; j < adresses.size(); j++) {
        if (adresses.at(j).getCity() == city) {
            MyFile << adresses.at(j).getCity();
            MyFile << "\n";
            MyFile << adresses.at(j).getStreet();
            MyFile << "\n";
            MyFile << adresses.at(j).getNumber();
            MyFile << "\n";
            for (int i = 0; i < universalAdresses.size(); i++) {
                if (universalAdresses.at(i).getCity() == city) {
                    MyFile << universalAdresses.at(i).getCountry();
                    MyFile << "\n";
                    MyFile << universalAdresses.at(i).getPostCode();
                    MyFile << "\n";
                }
            }
            MyFile << "-----------------------------";
            MyFile << "\n";
        }
        
    }
    MyFile.close();

    
    //читання інофрмації з файлу
    string line;
    
    ifstream MyReadFile("cities.txt");

    while (getline(MyReadFile, line)) {
        cout << line << endl;
    }

    MyReadFile.close();

}
