#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Звичайна рекурсивна функція створення
void Create(int* a, const int size, const int Low, const int High, int i = 0) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        Create(a, size, Low, High, i + 1);
    }
}

// 2. Звичайна рекурсивна функція виводу
void Print(const int* a, const int size, int i = 0) {
    cout << setw(6) << a[i];
    if (i < size - 1) {
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// 3. Звичайна рекурсивна функція суми (тільки додатні)
int Sum(const int* a, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    int s = (a[i] > 0) ? a[i] : 0;
    return s + Sum(a, size, i + 1);
}

// 4. Шаблонна рекурсивна функція виводу
template <typename T>
void Print(const T* a, const int size, int i = 0) {
    cout << setw(6) << a[i];
    if (i < size - 1) {
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// 5. Шаблонна рекурсивна функція суми (тільки додатні)
template <typename T>
T Sum(const T* a, const int size, int i = 0) {
    if (i >= size) {
        return T();
    }
    T s = (a[i] > 0) ? a[i] : T();
    return s + Sum(a, size, i + 1);
}

int main() {
    srand((unsigned)time(0));

    const int SIZE = 10;
    const int LOW = -10;
    const int HIGH = 10;

    // 1. Опрацювання звичайною рекурсивною функцією
    int a[SIZE];
    Create(a, SIZE, LOW, HIGH);
    cout << "Array a (int, Recursive):" << endl;
    Print(a, SIZE);

    int s1 = Sum(a, SIZE);
    cout << "Sum (Ordinary Recursive) = " << s1 << endl << endl;

    // 2. Опрацювання шаблонною рекурсивною функцією (int)
    int s2 = Sum<int>(a, SIZE);
    cout << "Sum<int> (Template Recursive) = " << s2 << endl << endl;

    // 3. Опрацювання шаблонною рекурсивною функцією (double)
    double b[SIZE] = { -2.5, 3.1, -0.4, 5.2, -8.0, 1.5, 0.0, -1.2, 4.4, -3.3 };
    cout << "Array b (double, Recursive):" << endl;
    Print<double>(b, SIZE);

    double s3 = Sum<double>(b, SIZE);
    cout << "Sum<double> (Template Recursive) = " << s3 << endl;

    return 0;
}