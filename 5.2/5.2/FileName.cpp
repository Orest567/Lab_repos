// Лабораторна робота № 5.2 (Варіант 8)
// Спосіб 2: double-функції
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Константа PI для обчислення pi/2
const double PI = 4.0 * atan(1.0);

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x"
        << " |" << setw(12) << "atan(x)"
        << " |" << setw(12) << "S"
        << " |" << setw(5) << "n" << " |" << endl;
    cout << "---------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(12) << setprecision(5) << atan(x)
            << " |" << setw(12) << setprecision(5) << s
            << " |" << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "---------------------------------------------------------" << endl;

    return 0;
}

double S(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = -1.0 / x; // Перший доданок при n = 0
    s = PI / 2.0 + a;    // Початкова сума pi/2 + a0

    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);

    return s;
}

double A(const double x, const int n, double a)
{
    double R = -(2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x); // Коефіцієнт рекурентності
    a *= R;
    return a;
}