#include <iostream>

using namespace std;

int gcd(int n, int m, int level, int& depth) {
    // Оновлюємо поточну глибину рекурсії
    if (level > depth) {
        depth = level;
    }

    cout << "Riven: " << level << " | Hlybyna: " << depth
        << " | Vkhidni dani: n = " << n << ", m = " << m << endl;

    // умова зупинки рекурсії
    if (m == 0) {
        return n;
    }

    // Рекурсивний крок
    return gcd(m, n % m, level + 1, depth);
}

int main() {
    int n, m;
    cout << "Vvedit dva naturalnykh chysla (n ta m): ";
    cin >> n >> m;

    // Перевірка на натуральність чисел
    if (n <= 0 || m <= 0) {
        cout << "Pomylka: Chysla povynni buty naturalnymy (bilshymy za 0)." << endl;
        return 1;
    }

    int depth = 0;
    // Запуск рекурсії з початковим рівнем 1
    int result = gcd(n, m, 1, depth);

    // Вивід остаточного результату
    cout << "-----------------------------------" << endl;
    cout << "Naibilshyi spilnyi dilnyk NSD(" << n << ", " << m << ") = " << result << endl;
    cout << "Zahalna hlybyna recursii: " << depth << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}