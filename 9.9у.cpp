// 9.9у.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

	//кількість парних стовпців
	int count = 0;
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0)
			count++;
	}


	cout << "Count : " <<count <<endl;
	//нова матриця

	int** b;
	b = new int* [n];
	for (int i = 0; i < n; i++)
		b[i] = new int[m + count];

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
	
	//вставляємо дані
	int index = 0;

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			b[i][index] = a[i][j];
			if((index + 1) <= (m + count-1))
				b[i][index+1] = column[i];
		}
		index+=2;
	}

	a = b;

	//виводимо матрицю
	cout << "New Matrix : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + count; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}