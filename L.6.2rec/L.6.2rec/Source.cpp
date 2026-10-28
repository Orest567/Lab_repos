#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High, int i = 0) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        Create(a, size, Low, High, i + 1); // Рекурсивний виклик для наступного елемента
    }
}

// Рекурсивне виведення масиву у рядок
void Print(const int* a, const int size, int i = 0) {
    cout << setw(5) << a[i];
    if (i < size - 1) {
        Print(a, size, i + 1); // Рекурсивний виклик для наступного елемента
    }
    else {
        cout << endl;
    }
}

// Рекурсивна перестановка елементів у зворотному порядку (Реверс)
void Reverse(int* a, int left, int right) {
    if (left >= right) {
        return; // Базовий випадок (умова зупинки)
    }

    // Перестановка поточних крайніх елементів
    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;

    // Рекурсивний виклик для наступної внутрішньої пари елементів
    Reverse(a, left + 1, right - 1);
}

int main() {
    srand(time(0));

    const int SIZE = 10;
    const int LOW = -10;
    const int HIGH = 20;

    int a[SIZE];

    // 1. Формування та виведення початкового масиву
    Create(a, SIZE, LOW, HIGH);
    cout << "Original array:" << endl;
    Print(a, SIZE);

    // 2. Виклик рекурсивного реверсу (передаємо ліву межу 0 та праву SIZE - 1)
    Reverse(a, 0, SIZE - 1);

    // 3. Виведення модифікованого (розвернутого) масиву
    cout << "Modified array (reversed):" << endl;
    Print(a, SIZE);

    return 0;
}