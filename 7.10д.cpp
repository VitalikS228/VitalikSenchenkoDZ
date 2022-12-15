// 7.10д.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include <string>

using namespace std;

//генерація повних квадратів чисел 0 - 100
int* fullKvadrat() {
	int a[100];
	for (int i = 0; i < 100; i++) {
		a[i] = pow(i,2);
	}
	return a;
}

//підрахунок повних квадратів в масиві
int count(int* a, int n) {
	//кількість 
	int c = 0;
	int* kv = fullKvadrat();
	//пробігаємо по половині масиву
	for (int i = 0; i < n/2; i++) {
		//пробігаємо по масиву повних квадратів
		for (int k = 0; k < 100; k++) {
			//якщо повний квадрат дорівнює добутку елементів масиву за умовою
			if (kv[k] == a[i] * a[n - 1 - i])
				//то такий добуток є повним квадратом, а значить збільшуємо лічильник
				c++;
		}
	}
	return c;
}

int main()
{
	const int n = 100;
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

	cout << "Count = " << count(a, n) << endl;

}
