// 7.9г.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include <string>

using namespace std;

int main()
{
	const int n = 10;
	int a[n];

	/* для генерації випадкових чисел: */
	srand(time(NULL));

	/* числа між 1 та 100: */

	//заповнюємо масив
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}


	//виводимо масив
	cout << "Array : " << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	//шукаємо мінімальнй елемент
	int min = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}

	cout << "Min = " << min;

}