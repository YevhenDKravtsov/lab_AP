#include <windows.h>
#include <iostream>
#include <limits>
using namespace std;

// If15: сума двох найбільших чисел.
void taskIf15() {
    double a, b, c, sum;
    cout << "Введіть три числа: ";
    if (!(cin >> a >> b >> c)) return;
    if (a <= b && a <= c) sum = b + c;
    else if (b <= a && b <= c) sum = a + c;
    else sum = a + b;
    cout << "Сума двох найбільших: " << sum << endl;
}

// If5: кількість додатних та від'ємних чисел.
void taskIf5() {
    int a, b, c;
    cout << "Введіть три цілі числа: ";
    if (!(cin >> a >> b >> c)) return;
    int positive = 0, negative = 0;
    if (a > 0) ++positive; else if (a < 0) ++negative;
    if (b > 0) ++positive; else if (b < 0) ++negative;
    if (c > 0) ++positive; else if (c < 0) ++negative;
    cout << "Додатних: " << positive
         << ", від'ємних: " << negative << endl;
}

// Завдання 2, варіант 20: світло-зелена область.
void taskVariant20() {
    double a, r, x, y;
    cout << "Введіть сторону квадрата a та радіус r: ";
    if (!(cin >> a >> r)) return;
    if (a <= 0 || r <= 0 || r >= a / 2) {
        cout << "Некоректні розміри." << endl;
        return;
    }
    cout << "Введіть координати x та y: ";
    if (!(cin >> x >> y)) return;
    double distance = x * x + y * y;
    bool inSquare = x >= -a / 2 && x <= 0 &&
                    y >= 0 && y <= a / 2;
    bool inGreen = inSquare && y >= -x &&
                   distance >= r * r;
    if (inGreen)
        cout << "Точка належить світло-зеленій області." << endl;
    else
        cout << "Точка не належить світло-зеленій області." << endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int choice;
    while (true) {
        cout << "\n=== Лабораторна робота №3 ===\n"
             << "1 - If15 (сума двох найбільших)\n"
             << "2 - If5 (кількість додатних і від'ємних)\n"
             << "3 - Варіант 20 (світло-зелена область)\n"
             << "0 - Вихід\nВаш вибір: ";
        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка: введіть номер пункту." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: taskIf15(); break;
        case 2: taskIf5(); break;
        case 3: taskVariant20(); break;
        case 0: cout << "Завершення роботи." << endl; return 0;
        default: cout << "Невідомий пункт меню." << endl;
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некоректні вхідні дані." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}