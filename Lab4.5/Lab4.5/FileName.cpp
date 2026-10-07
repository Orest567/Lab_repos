#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    double x, y, R;
    srand((unsigned)time(NULL));

    cout << "R = "; cin >> R;

    cout << endl << "=== 1 sposib ===" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        // Перевірка попадання в область Варіанта 8
        if ((x >= 0 && x * x + y * y <= R * R) ||
            (x <= 0 && x >= -R && y >= -R && y <= R && (y >= -x || y <= x)))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << "=== 2 sposib ===" << endl;
    cout << endl << fixed;

    for (int i = 0; i < 10; i++)
    {
        // Генерація випадкових чисел x та y в інтервалі [-R; R]
        x = 2.0 * R * rand() / RAND_MAX - R;
        y = 2.0 * R * rand() / RAND_MAX - R;

        // Перевірка тієї ж умови для випадкових координат
        if ((x >= 0 && x * x + y * y <= R * R) ||
            (x <= 0 && x >= -R && y >= -R && y <= R && (y >= -x || y <= x)))
            cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << " " << "yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << " " << "no" << endl;
    }

    return 0;
}
