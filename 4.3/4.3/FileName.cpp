#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c, xp, xk, dx, x, F;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "X_poch = "; cin >> xp;
    cout << "X_kin = "; cin >> xk;
    cout << "dX = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "F" << " |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk + dx / 2)
    {
        if (c < 0 && a != 0)
        {
            F = -a * x * x;
        }
        else if (c > 0 && a == 0)
        {
            F = (a - x) / (c * x);
        }
        else
        {
            F = x / c;
        }

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(3) << F
            << " |" << endl;

        x += dx;
    }

    cout << "---------------------------" << endl;

    return 0;
}