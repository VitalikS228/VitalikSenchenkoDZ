// 8.12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	int a[n][m];

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
			cout<<a[i][j] <<" ";
		}
		cout << endl;
	}

	//шукаэмо мінімальний та максимальний елементи матриці та їх індекси стовбців
	int min = a[0][0];
	int indexMin = -1;
	int max = a[0][0];
	int indexMax = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
				indexMin = j;
			}
				
			if (a[i][j] > max) {
				max = a[i][j];
				indexMax = j;
			}
		}
	}
	cout << "Min : " << min << endl;
	cout << "Index Min : " << indexMin << endl;
	cout << "Max : " << max << endl;
	cout << "Index Max : " << indexMax << endl;

	//міняємо місцями

	for (int i = 0; i < n; i++) {
		int temp = a[i][indexMin];
		a[i][indexMin] = a[i][indexMax];
		a[i][indexMax] = temp;
	}

	//виводимо матрицю
	cout << "Matrix : " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}



}
