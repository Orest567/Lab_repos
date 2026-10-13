// Lab 5_1
// Варіант 8
#include <iostream>
#include <cmath>

using namespace std;

double g(const double a, const double b);

int main() 
{
	double s, t;
	cout << "s ="; cin >> s;
	cout << "t ="; cin >> t;

	double num = g(s * s, t + 1) + g(t * t, s + 1);
	double denum = 1 + pow(g(s + t, s * t), 2);

	double result = num / denum;
	cout << "c = " << result << endl;
	return 0;
}

double g(const double a, const double b)
{
	return sin(a * b) / (a * a + b * b);
}
