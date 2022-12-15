// 10.6е.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

//книга
struct Book {
    int ISBN;
    string author;
    string title;
};

//читач
struct Reader {
    int number;
    string fio;
    string date;
};

//бланк
struct Blank {
    Book book;
    Reader reader;
};

//основна програма
int main()
{
    Book book;
    book.ISBN = 1234;
    book.author = "W. Shekspir";
    book.title = "Romeo and Julliet";

    Reader reader = { 1, "OLeg", "2022" };

    Blank blank = { book,reader };

    cout << blank.book.ISBN << endl;
    cout << blank.book.author<< endl;
    cout << blank.book.title << endl;
    cout << blank.reader.number<< endl;
    cout << blank.reader.fio << endl;
    cout << blank.reader.date << endl;

}
