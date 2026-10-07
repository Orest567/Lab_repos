#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double R, xp, xk, dx, x, y;

    cout << "R = "; cin >> R;
    cout << "X_poch = "; cin >> xp;
    cout << "X_kin = "; cin >> xk;
    cout << "dX = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "y" << " |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x < -8 - R)
        {
            y = -R;
        }
        else if (x <= -8 + R)
        {
            y = -R + sqrt(R * R - (x + 8) * (x + 8));
        }
        else if (x <= 2)
        {
            y = 2 + (2 + R) / (10 - R) * (x - 2);
        }
        else if (x <= 6)
        {
            y = 0;
        }
        else
        {
            y = (x - 6) * (x - 6);
        }

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(3) << y
            << " |" << endl;

        x += dx;
    }

    cout << "---------------------------" << endl;

    return 0;
}