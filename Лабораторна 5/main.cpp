#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Перевірка, що після числа в рядку немає інших символів.
bool emptyTail()
{
    string tail;
    getline(cin, tail);
    return tail.find_first_not_of(" \t\r") == string::npos;
}

// Введення скінченного дійсного числа.
double inputReal(const string &message)
{
    double value;
    while (true) {
        cout << message;
        const bool readOk = static_cast<bool>(cin >> value);
        const bool tailOk = readOk ? emptyTail() : false;
        if (readOk && tailOk && isfinite(value)) return value;
        if (!readOk) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Помилка! Введіть дійсне число (десятковий роздільник — крапка).\n";
    }
}

// Введення натурального числа в заданих межах.
int inputNatural(const string &message, int maxValue)
{
    int value;
    while (true) {
        cout << message;
        const bool readOk = static_cast<bool>(cin >> value);
        const bool tailOk = readOk ? emptyTail() : false;
        if (readOk && tailOk && value >= 1 && value <= maxValue) return value;
        if (!readOk) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Помилка! Введіть ціле число від 1 до " << maxValue << ".\n";
    }
}

// Введення пункту меню (від 0 до 3).
int inputMenu()
{
    int value;
    while (true) {
        cout << "Ваш вибір: ";
        const bool readOk = static_cast<bool>(cin >> value);
        const bool tailOk = readOk ? emptyTail() : false;
        if (readOk && tailOk) return value;
        if (!readOk) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Помилка! Введіть цілий номер пункту.\n";
    }
}

// Завдання 1, варіант 18: помаранчеві області рисунка.
void task1()
{
    cout << "\nЗавдання 1. Варіант 18.\n";
    double r;
    do {
        r = inputReal("Введіть радіус кіл r (> 0): ");
        if (r <= 0 || r > 1000000.0) {
            cout << "Радіус має бути більшим за 0 і не перевищувати 1000000.\n";
        }
    } while (r <= 0 || r > 1000000.0);

    const int n = inputNatural("Введіть кількість точок n: ", 10000);
    int count = 0;

    for (int i = 1; i <= n; i++) {
        cout << "\nТочка " << i << ":\n";
        const double x = inputReal("  x = ");
        const double y = inputReal("  y = ");

        // Помаранчевий верхній лівий трикутник:
        // -2r <= x <= 0, 0 <= y <= x + 2r.
        const bool upperTriangle =
            (x >= -2*r && x <= 0 && y >= 0 && y <= x + 2*r);

        // Помаранчева ділянка внизу ліворуч:
        // всередині трикутника, праворуч і нижче від центра
        // нижнього кола, але поза колом із центром (-r,-r).
        const bool lowerTriangle =
            (x >= -2*r && x <= 0 && y >= -2*r && y <= 0 && x+y >= -2*r);
        const double distanceSquared = (x+r)*(x+r) + (y+r)*(y+r);
        const bool lowerOrange =
            lowerTriangle && (x >= -r) && (y <= -r) &&
            (distanceSquared >= r*r);

        if (upperTriangle || lowerOrange) {
            count++;
            cout << "Точка належить помаранчевій області.\n";
        } else {
            cout << "Точка НЕ належить помаранчевій області.\n";
        }
    }

    cout << "\nКількість точок у помаранчевих областях: " << count << " з " << n << ".\n";
}

// Обчислення степеня від'ємної основи, якщо показник
// можна подати дробом з непарним знаменником.
bool realPower(double base, double exponent, double &result)
{
    if (base >= 0) {
        result = pow(base, exponent);
        return isfinite(result);
    }

    // У дійсних числах (-a)^(p/q) визначене за непарного q.
    // Перевіряємо прості раціональні показники (q <= 999).
    for (int q = 1; q <= 999; q += 2) {
        const double numeratorDouble = round(exponent * q);
        if (!isfinite(numeratorDouble) || fabs(numeratorDouble) > 1000000000000.0) {
            continue;
        }
        if (fabs(exponent - numeratorDouble / q) <= 1e-12) {
            const long long numerator = static_cast<long long>(numeratorDouble);
            const double magnitude = pow(-base, exponent);
            result = (numerator % 2 == 0) ? magnitude : -magnitude;
            return isfinite(result);
        }
    }
    return false;
}

// Завдання 2, варіант 24: степінь від суми ряду.
void task2()
{
    cout << "\nЗавдання 2. Варіант 24.\n";
    double x;
    do {
        x = inputReal("Введіть x (x >= 0): ");
        if (x < 0) cout << "Помилка! Під квадратним коренем x >= 0.\n";
    } while (x < 0);
    const int n = inputNatural("Введіть натуральне n (1..1000): ", 1000);

    const double pi = acos(-1.0);
    const double a = sqrt(x) - pi / 2.0;
    double term = a;  // k=0: (-1)^0 * a^1 / 1! = a.
    double sum = 0;

    cout << fixed << setprecision(12);
    for (int k = 0; k <= n; k++) {
        if (k > 0) {
            // Перехід до наступного члена без повторного обчислення факторіала.
            term *= -(a*a) / (2.0*k * (2.0*k + 1.0));
        }
        if (!isfinite(term) || !isfinite(sum + term)) {
            cout << "Помилка: проміжне значення надто велике.\n";
            return;
        }
        sum += term;
        if ((k+1) % 3 == 0) {
            cout << scientific << setprecision(12)
                 << "Елемент №" << k+1 << " (k=" << k << "): " << term << '\n'
                 << fixed << setprecision(12);
        }
    }

    const double base = -sum;
    const double exponent = x / 3.0;
    double result;

    cout << "Обчислена сума: " << sum << '\n';
    cout << "Основа степеня (-сума): " << base << '\n';
    cout << "Показник степеня x/3: " << exponent << '\n';

    if (!realPower(base, exponent, result)) {
        cout << "Неможливо обчислити дійсний результат для цього x, n "
             << "(або результат за межами типу double).\n";
        cout << "Для від'ємної основи підтримуються показники з "
             << "непарним знаменником до 999.\n";
        return;
    }
    cout << "Значення виразу: " << result << '\n';
}

// Завдання 3, варіант 16: сума n^3 * exp(2n+1) / n!.
void task3()
{
    cout << "\nЗавдання 3. Варіант 16.\n";
    const double epsilon = 1E-10;
    const double g = 1E5;
    const int M = inputNatural("Введіть крок виведення M (> 0): ", 1000);
    const double e2 = exp(2.0);

    int n = 1;
    double u = exp(3.0);  // u1 = 1^3 * exp(3) / 1!.
    double sum = 0.0;

    cout << fixed << setprecision(15);
    cout << "Межі: epsilon=" << epsilon << ", g=" << g << '\n';

    // Зупинка, якщо |u_n| < epsilon АБО |u_n| > g.
    while (fabs(u) >= epsilon && fabs(u) <= g) {
        sum += u;
        if (n == 1 || n % M == 0) {
            cout << "n=" << n << "  u=" << u << "  сума=" << sum << '\n';
        }
        const int nextN = n + 1;
        // u_(n+1)/u_n = exp(2)*(n+1)^2/n^3.
        u *= e2 * nextN * nextN / (1.0*n*n*n);
        n = nextN;
    }

    cout << "Зупинка при n=" << n << ", u=" << u << '\n';
    cout << "Накопичена часткова сума: " << sum << '\n';

    // За ознакою Даламбера відношення сусідніх членів -> 0,
    // тому ряд математично збігається (навіть якщо спрацює g).
    cout << "Математичний висновок: ряд ЗБІЖНИЙ.\n";
    if (fabs(u) > g) {
        cout << "Увага: член ряду перевищив g. Це НЕ доказ розбіжності!\n";
        cout << "Поріг g=100000 замалий для цього варіанта; "
             << "чисельне підсумовування перервано достроково.\n";
    } else {
        cout << "Задана точність epsilon досягнута.\n";
    }

    // Незалежна точна формула перевірки:
    // sum(n^3*t^n/n!) = (t^3+3*t^2+t)*exp(t), t=exp(2).
    const double t = exp(2.0);
    const double exactSum = exp(1.0 + t) * (t*t*t + 3*t*t + t);
    cout << "Повна сума за математичною формулою: " << exactSum << '\n';
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int menu;
    do {
        cout << "\n===== ЛАБОРАТОРНА РОБОТА №5 =====\n";
        cout << "1 - Завдання 1 (варіант 18, геометрія)\n";
        cout << "2 - Завдання 2 (варіант 24, обчислення виразу)\n";
        cout << "3 - Завдання 3 (варіант 16, збіжність ряду)\n";
        cout << "0 - Вихід\n";
        menu = inputMenu();

        switch (menu) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Завершення програми.\n"; break;
            default: cout << "Невідомий пункт меню. Спробуйте ще раз.\n";
        }
    } while (menu != 0);

    return 0;
}
