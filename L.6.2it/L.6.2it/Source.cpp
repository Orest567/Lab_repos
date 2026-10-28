#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Виведення масиву у рядок із форматуванням
void Print(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(5) << a[i];
    }
    cout << endl;
}

// Перестановка елементів у зворотному порядку (Ітераційний спосіб)
void Reverse(int* a, const int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
}

int main() {
    srand(time(0));

    const int SIZE = 10;
    const int LOW = -10;
    const int HIGH = 20;

    int a[SIZE];

    Create(a, SIZE, LOW, HIGH);
    cout << "Original array:" << endl;
    Print(a, SIZE);

    Reverse(a, SIZE);

    cout << "Modified array (reversed):" << endl;
    Print(a, SIZE);

    return 0;
}