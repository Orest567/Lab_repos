#include <iostream>
#include <cmath>

using namespace std;

// 5) Ітераційний спосіб
double P0(const int K, const int N)
{
    double p = 1.0;
    for (int i = K; i <= N; i++)
        p *= (1.0 * K / i + 1.0 * i / N);
    return p;
}

// 3)рекурсивний підйом, параметр зростає (i++)
double P1(const int K, const int N, const int i)
{
    if (i > N)
        return 1.0;
    else
        return (1.0 * K / i + 1.0 * i / N) * P1(K, N, i + 1);
}

// 4)рекурсивний підйом, параметр спадає (i--)
double P2(const int K, const int N, const int i)
{
    if (i < K)
        return 1.0;
    else
        return (1.0 * K / i + 1.0 * i / N) * P2(K, N, i - 1);
}

// 2)рекурсивний спуск, параметр зростає (i++)
double P3(const int K, const int N, const int i, double t)
{
    t = t * (1.0 * K / i + 1.0 * i / N);
    if (i >= N)
        return t;
    else
        return P3(K, N, i + 1, t);
}

// 1)рекурсивний спуск, параметр спадає (i--)
double P4(const int K, const int N, const int i, double t)
{
    t = t * (1.0 * K / i + 1.0 * i / N);
    if (i <= K)
        return t;
    else
        return P4(K, N, i - 1, t);
}

int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(iter)        P0 = " << P0(K, N) << endl;
    cout << "(rec up ++)   P1 = " << P1(K, N, K) << endl;
    cout << "(rec up --)   P2 = " << P2(K, N, N) << endl;
    cout << "(rec down ++) P3 = " << P3(K, N, K, 1.0) << endl;
    cout << "(rec down --) P4 = " << P4(K, N, N, 1.0) << endl;

    return 0;
}