#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Допоміжна функція s(x)
double s(const double x)
{
    if (abs(x) >= 1.0)
    {
        double num = 1.0 + x * x + sqrt(abs(sin(x)));
        double denom = pow(sin(2.0 * x * x), 2) + 1.0;
        return num / denom;
    }
    else
    {
        // Обчислення першої суми (i від 0 до 5)
        double S1 = 0;
        double a = 1.0; // i = 0 => x^0 / 0! = 1
        S1 += a;
        for (int i = 1; i <= 5; i++)
        {
            a *= x / i; // рекурентне співвідношення R_i = x / i
            S1 += a;
        }

        // Обчислення другої суми (k від 1 до 6)
        double S2 = 0;
        double b = x; // k = 1 => x^1 / 1! = x
        S2 += b;
        for (int k = 2; k <= 6; k++)
        {
            b *= x / k; // рекурентне співвідношення R_k = x / k
            S2 += b;
        }

        return S1 + S2;
    }
}

int main()
{
    double rp, rk;
    int n;

    cout << "rp = "; cin >> rp;
    cout << "rk = "; cin >> rk;
    cout << "n = "; cin >> n;

    double dr = (rk - rp) / n;
    double r = rp;

    // Заголовок та шапка таблиці
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "|" << setw(18) << "r" << " |" << setw(18) << "z" << " |" << endl;
    cout << "---------------------------------------" << endl;

    cout << fixed << setprecision(5);

    while (r <= rk + dr / 2.0) // dr/2 для уникнення помилок округлення double
    {
        // Перевіряємо область визначення коренів (r >= 0)
        if (r < 0)
        {
            cout << "|" << setw(18) << r << " |" << setw(18) << "не визначено" << " |" << endl;
        }
        else
        {
            double z = s(sqrt(r) + 1.0) - pow(s(sqrt(r) - 1.0), 2) + 1.0;
            cout << "|" << setw(18) << r << " |" << setw(18) << z << " |" << endl;
        }
        r += dr;
    }

    cout << "---------------------------------------" << endl;

    return 0;
}