// 15.13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

//описані класи та методи для них
//там звичайна математика
class Vector3 {
private:
    int* a;
public:
    Vector3() {
        int k = 1;
        a = new int[3];
        for (int i = 0; i < 3; i++) {
            a[i] = k;
            k++;
        }
    }
    void toString() {
        for (int i = 0; i < 3; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int Abs() {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += abs(a[i]);
        }
        return sum;
    }

    int* getA() {
        return a;
    }

    const void operator+(const Vector3& vector) const {
        for (int i = 0; i < 3; i++) {
            a[i] += vector.a[i];
        }
    }
    const void operator-(const Vector3& vector) const {
        for (int i = 0; i < 3; i++) {
            a[i] -= vector.a[i];
        }
    }
    const int operator*(const Vector3& vector) const {
        int x = 0;
        for (int i = 0; i < 3; i++) {
            x += a[i] * vector.a[i];
        }
    }
};

class Matrix3 {
private:
    int** a;
public:
    Matrix3() {
        a = new int* [3];
        for (int i = 0; i < 3; i++)
            a[i] = new int[3];
        int k = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = k;
                k++;
            }
        }
    }
    void toString() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    int Abs() {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum += abs(a[i][j]);
            }
        }
        return sum;
    }
    int det() {
        return a[0][0] * a[1][1] * a[2][2] +
            a[0][1] * a[1][2] * a[2][0] +
            a[0][2] * a[1][0] * a[2][1] -
            a[0][2] * a[1][1] * a[2][0] -
            a[0][0] * a[1][2] * a[2][1] -
            a[1][1] * a[1][0] * a[2][2];
    }


    const void operator+(const Matrix3& matrix) const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] += matrix.a[i][j];
            }
        }
    }

    const void operator-(const Matrix3& matrix) const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] -= matrix.a[i][j];
            }
        }
    }

    const void operator*(const Matrix3& matrix) const {
        int** b;
        b = new int* [3];
        for (int i = 0; i < 3; i++)
            b[i] = new int[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = 0;
            }
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                {
                    b[i][j] += a[i][k] * matrix.a[k][j];
                }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = b[i][j];
            }
        }
    }
    int* operator*(Vector3& vector) const {
        int* b;
        b = new int[3];

        for (int i = 0; i < 3; i++) {
            b[i] = 0;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                b[i] += (a[i][j] * vector.getA()[i]);
            }
        }
        return b;
    }

};

//перевірка усіх методів класів в основній програмі
int main()
{
    Matrix3 matrix;
    Vector3 vector;

    matrix.toString();
    vector.toString();
    cout << endl;
    cout << matrix.Abs() << endl;
    
    cout << endl;
    cout << vector.Abs() << endl;
    
    cout << endl;
    cout << matrix.det() << endl;
    cout << endl;
    
    Matrix3 matrix2;

    matrix + matrix2;

    matrix.toString();
    cout << endl;

    matrix - matrix2;

    matrix.toString();
    cout << endl;

    matrix* matrix2;

    matrix.toString();
    cout << endl;
    

    int* r = matrix2 * vector;

    for (int i = 0; i < 3; i++) {
        cout << r[i] << " ";
    }
    cout << endl;

    Vector3 vector2;

    cout << vector * vector2;
}
