#include <iostream>
#include <iomanip>
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main() {
    cout << "x_p (> 1) = "; cin >> x_p;
    cout << "x_k (> 1) = "; cin >> x_k;
    cout << "dx = ";        cin >> dx;
    cout << "e = ";         cin >> e;
    cout << endl;

    if (x_p <= 1.0 || x_k <= 1.0 || dx <= 0.0 || e <= 0.0) {
        cout << "Pomylka: dlya variantu 8 neobkhidno x > 1, dx > 0, e > 0." << endl;
        return 1;
    }

    // Заголовок та шапка таблиці
    cout << "          Tabulyatsiya funktsiyi arctg(x)" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x"
        << " |" << setw(14) << "arctg(x)"
        << " |" << setw(14) << "Suma ryadu"
        << " |" << setw(10) << "Dodankiv" << " |" << endl;
    cout << "---------------------------------------------------------" << endl;

    cout << fixed;
    x = x_p;
    while (x <= x_k + dx / 2.0) {
        sum();
        cout << "|" << setw(10) << setprecision(3) << x
            << " |" << setw(14) << setprecision(6) << atan(x)
            << " |" << setw(14) << setprecision(6) << s
            << " |" << setw(10) << (n + 1) << " |" << endl;
        x += dx;
    }
    cout << "---------------------------------------------------------" << endl;

    return 0;
}