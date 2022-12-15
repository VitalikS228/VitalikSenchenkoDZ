// 8.23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

//поворот на 90 градусів
int** turn90(int n, int** a) {
	int i, j;
	int** b;
	b = new int* [n];
	for (i = 0; i < n; i++) 
		b[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			b[j][n - i - 1] = a[i][j];
		}
	return b;
}

//вивід матриці
void print(int n, int** a2) {
	//виводимо матрицю
	cout << "Matrix : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a2[i][j] << " ";
		}
		cout << endl;
	}
}

//основна програма
int main()
{
	const int n = 5;
	int **a;

	a = new int* [2*n];
	for (int i = 0; i < 2*n; i++) 
		a[i] = new int[2*n];

	/* для генерації випадкових чисел: */
	srand(time(NULL));

	/* числа між 1 та 100: */

	//заповнюємо Матрицю
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			a[i][j] = rand() % 100 + 1;
		}
	}

	//вивід матриці
	print(2 * n, a);
	//три поворота по 90 градусів = 270 градусів
	a = turn90(2 * n, a);
	a = turn90(2 * n, a);
	a = turn90(2 * n, a);
	
	//вивід
	print(2 * n, a);

	//ще один поворот на 90 градусів - начальна матриця
	a = turn90(2 * n, a);

	print(2 * n, a);
}