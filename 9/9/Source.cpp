#include <iostream>
#include "Header.h"

#define Z 15

using namespace std;

int main() {
    double x, y, w;

    cout << "Lab 9.2. Vykorystannya makrovyznachen ta dyrektyv preprocesora" << endl;
    cout << "Potochne znachennya Z = " << Z << endl << endl;

    cout << "Vvedit x: ";
    cin >> x;
    cout << "Vvedit y: ";
    cin >> y;
    cout << endl;

   
#if Z > 10
    cout << "Vykorystovuyetsya gilka dlya Z > 10: w = max(x^3, (x + y)^2)" << endl;
    double part1 = CUBE(x);
    double part2 = SQR(x + y);
    PRINT(part1);
    PRINT(part2);
    w = MAX(part1, part2);
#else
    cout << "Vykorystovuyetsya gilka dlya Z <= 10: w = min(|x - z|, |x + z|)" << endl;
    double part1 = ABS(x - Z);
    double part2 = ABS(x + Z);
    PRINT(part1);
    PRINT(part2);
    w = MIN(part1, part2);
#endif

    cout << "Rezultat obchyslen:" << endl;
    PRINT(w);

    return 0;
}