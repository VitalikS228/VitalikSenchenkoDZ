// 9.9б.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int n = 5;
	const int m = 4;
	int** a;

	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];

	/* для генерації випадкових чисел: */
	srand(time(NULL));

	/* числа між 1 та 100: */

	//заповнюємо Матрицю
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 100 + 1;
		}
	}

	//виводимо матрицю
	cout << "Matrix : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	int index = -1;

	while (index < 0 || index >= m) {
		cout << "Enter index for inserting: ";
		cin >> index;
	}


	//нова матриця

	int** b;
	b = new int* [n];
	for (int i = 0; i < n; i++)
		b[i] = new int[m+1];

	//новий совбець для вставки
	int column[n];

	for (int i = 0; i < n; i++) {
		column[i] = rand() % 100 + 1;
	}

	cout << "New COLUMN" << endl;
	for (int i = 0; i < n; i++) {
		cout << column[i] << " ";
	}
	cout << endl;

	//копіюємо до індекса (включно)
	for (int j = 0; j <=index; j++)
	{
		for (int i = 0; i < n; i++) {
			b[i][j] = a[i][j];
		}
	}
	
	//копіюємо елементи колонки нової
	for (int i = 0; i < n; i++) {
		b[i][index + 1] = column[i];
	}

	//після індекса
	for (int j = index + 1; j < m; j++)
	{
		for (int i = 0; i < n; i++) {
			b[i][j+1] = a[i][j];
		}
	}

	a = b;

	//виводимо матрицю
	cout << "New Matrix : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m+1; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}


