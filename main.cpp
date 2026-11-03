#include <windows.h>
#include <iostream>
#include <limits>
using namespace std;

// Оголошення функцій перед main().
void task1();
void task2();
void task3();

bool inputProc7(int &K);
void InvDigits(int &K);
void outputProc7(int K);

bool inputProc10(int &A, int &B, int &C, int &D);
void Swap(int &X, int &Y);
void outputProc10(int A, int B, int C, int D);

bool inputInteger18(int &N);
int thousandsDigit(int N);
void outputInteger18(int digit);

void clearInput();

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice = -1;

    do {
        cout << "\n===== ЛАБОРАТОРНА РОБОТА №4 =====\n";
        cout << "1 - Proc7 (зворотний порядок цифр)\n";
        cout << "2 - Proc10 (обмін значеннями)\n";
        cout << "3 - Integer18 (цифра тисяч)\n";
        cout << "0 - Завершити програму\n";
        cout << "Оберіть пункт меню: ";

         if (!(cin >> choice)) {
            if (cin.eof()) {
                cout << "Введення недоступне. Завершення програми.\n";
                break;
            }

            cout << "Помилка: введіть цілий номер пункту меню.\n";
            clearInput();
            continue;
        }
        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Роботу завершено.\n"; break;
        default: cout << "Невідомий пункт меню.\n";
        }
    } while (choice != 0);

    return 0;
}

// Очищення потоку після помилки введення.
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Завдання 1. Proc7.
void task1()
{
    int K;
    for (int i = 1; i <= 5; i++) {
        cout << "\nЧисло " << i << " з 5:\n";
        if (!inputProc7(K)) {
            cout << "Помилка: потрібне ціле число від 1 до 9999.\n";
            return;
        }
        InvDigits(K);
        outputProc7(K);
    }
}

// Введення та перевірка числа для Proc7.
bool inputProc7(int &K)
{
    cout << "Введіть число K (1..9999): ";
    if (!(cin >> K)) {
        clearInput();
        return false;
    }
    return K > 0 && K < 10000;
}

// Розвертає цифри числа K, змінюючи сам параметр.
void InvDigits(int &K)
{
    int reversed = 0;
    while (K > 0) {
        reversed = reversed * 10 + K % 10;
        K = K / 10;
    }
    K = reversed;
}

// Виведення результату Proc7.
void outputProc7(int K)
{
    cout << "Число після перестановки цифр: " << K << '\n';
}

// Завдання 2. Proc10.
void task2()
{
    int A, B, C, D;
    if (!inputProc10(A, B, C, D)) {
        cout << "Помилка: потрібно ввести чотири цілі числа.\n";
        return;
    }

    // Послідовність обмінів точно за умовою задачі.
    Swap(A, B);
    Swap(C, D);
    Swap(B, C);

    outputProc10(A, B, C, D);
}

// Введення чотирьох цілих чисел.
bool inputProc10(int &A, int &B, int &C, int &D)
{
    cout << "Введіть A, B, C, D через пробіл: ";
    if (!(cin >> A >> B >> C >> D)) {
        clearInput();
        return false;
    }
    return true;
}

// Процедура обміну значеннями двох змінних.
void Swap(int &X, int &Y)
{
    int temp = X;
    X = Y;
    Y = temp;
}

// Виведення змінних після всіх обмінів.
void outputProc10(int A, int B, int C, int D)
{
    cout << "Після обмінів: A = " << A
         << ", B = " << B
         << ", C = " << C
         << ", D = " << D << '\n';
}

// Завдання 3. Integer18.
void task3()
{
    int N;
    if (!inputInteger18(N)) {
        cout << "Помилка: потрібне ціле число, більше за 999.\n";
        return;
    }

    int digit = thousandsDigit(N);
    outputInteger18(digit);
}

// Введення та перевірка числа для Integer18.
bool inputInteger18(int &N)
{
    cout << "Введіть ціле число N (> 999): ";
    if (!(cin >> N)) {
        clearInput();
        return false;
    }
    return N > 999;
}

// Одна операція ділення та одна операція остачі.
int thousandsDigit(int N)
{
    return (N / 1000) % 10;
}

// Виведення цифри розряду тисяч.
void outputInteger18(int digit)
{
    cout << "Цифра розряду тисяч: " << digit << '\n';
}
