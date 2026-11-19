#pragma once
#include <iostream>

using namespace std;

#define SQR(a) ((a) * (a))

#define CUBE(a) ((a) * (a) * (a))

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define ABS(a) (((a) < 0) ? -(a) : (a))

#define PRINT(var) cout << #var << " = " << (var) << endl