#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(15) << "y" << " |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        A = 2 + 6 * x;

        if (x <= 0)
            B = log(cos(x)) + pow(x, 5);
        else if (x <= 3)
            B = 1.0 / tan((1 + log(x)) / 3.0);
        else
            B = 12 * x - pow(x, 8);

        y = A + B;

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(15) << setprecision(3) << y
            << " |" << endl;

        x += dx;
    }
    cout << "---------------------------" << endl;

    return 0;
}