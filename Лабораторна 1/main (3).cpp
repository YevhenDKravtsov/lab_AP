/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    // задача 1
    // декларація змінних
    double L, R, S;

    // введення змінної
    cout << "Введіть довжину кола L: ";
    cin >> L;

    // розрахунок результату
    R = L / (2 * 3.14);
    S = 3.14 * R * R;

    // вивід результату
    cout << "Радіус: " << R << endl;
    cout << "Площа: " << S << endl;


    // задача 2
    // декларація змінних
    double TF, TC;

    // введення змінної
    cout << "Введіть температуру TF: ";
    cin >> TF;

    // розрахунок результату
    TC = (TF - 32) * 5.0 / 9.0;

    // вивід результату
    cout << "Температура у градусах Цельсія: " << TC << endl;


    // задача 3
    // декларація змінних
    int A, B, C, T;

    // введення змінних
    cout << "Введіть значення A, B, C: ";
    cin >> A >> B >> C;

    // переміщення значень змінних
    T = A;
    A = C;
    C = B;
    B = T;

    // вивід результату
    cout << "Нові значення:" << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;

    return 0;
}