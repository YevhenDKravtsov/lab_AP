/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <limits>
using namespace std;
// If15: сума двох найбільших чисел.
void taskIf15() {
    double a, b, c, result;
    cout << "Введіть три числа: ";
    if (!(cin >> a >> b >> c)) return;
    if (a <= b && a <= c) result = b + c;
    else if (b <= a && b <= c) result = a + c;
    else result = a + b;
    cout << "Сума двох найбільших: " << result << "\n";
}
// If5: кількість додатних і від'ємних чисел.
void taskIf5() {
    int a, b, c;
    cout << "Введіть три цілі числа: ";
    if (!(cin >> a >> b >> c)) return;
    int positive = 0, negative = 0;
    if (a > 0) ++positive; else if (a < 0) ++negative;
    if (b > 0) ++positive; else if (b < 0) ++negative;
    if (c > 0) ++positive; else if (c < 0) ++negative;
    cout << "Додатних: " << positive
         << ", від'ємних: " << negative << "\n";
}
// If20: найближча до A точка.
void taskIf20() {
    double a, b, c, ab, ac;
    cout << "Введіть координати A, B, C: ";
    if (!(cin >> a >> b >> c)) return;
    ab = a - b;
    ac = a - c;
    if (ab < 0) ab = -ab;
    if (ac < 0) ac = -ac;
    if (ab < ac)
         cout << "Найближча точка: B; відстань: " << ab << "\n";
    else if (ac < ab)
         cout << "Найближча точка: C; відстань: " << ac << "\n";
    else
         cout << "B і C рівновіддалені від A; відстань: "
              << ab << "\n";
}
int main() {
    int choice;
    while (true) {
        cout << "\n=== Лабораторна робота №3 ===\n"
              << "1 - If15 (сума двох найбільших)\n"
              << "2 - If5 (кількість додатних і від'ємних)\n"
              << "3 - If20 (найближча точка)\n"
              << "0 - Вихід\nВаш вибір: ";
        if (!(cin >> choice)) {
             if (cin.eof()) break;
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             cout << "Помилка: введіть номер пункту.\n";
             continue;
        }
        switch (choice) {
             case 1: taskIf15(); break;
             case 2: taskIf5(); break;
             case 3: taskIf20(); break;
             case 0: cout << "Завершення роботи.\n"; return 0;
             default: cout << "Невідомий пункт меню.\n";
        }
        if (cin.fail()) {
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             cout << "Некоректні вхідні дані.\n";
        }
    }
    return 0;
}
