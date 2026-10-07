#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, N, i;
    double P;

    cout << "k = "; cin >> k;
    cout << "N = "; cin >> N;

    // 1)
    P = 1.0;
    i = k;
    while (i <= N)
    {
        P *= (1.0 * k / i + 1.0 * i / N);
        i++;
    }
    cout << P << endl;

    // 2)
    P = 1.0;
    i = k;
    do {
        P *= (1.0 * k / i + 1.0 * i / N);
        i++;
    } while (i <= N);
    cout << P << endl;

    // 3)
    P = 1.0;
    for (i = k; i <= N; i++)
    {
        P *= (1.0 * k / i + 1.0 * i / N);
    }
    cout << P << endl;

    // 4) 
    P = 1.0;
    for (i = N; i >= k; i--)
    {
        P *= (1.0 * k / i + 1.0 * i / N);
    }
    cout << P << endl;

    return 0;
}