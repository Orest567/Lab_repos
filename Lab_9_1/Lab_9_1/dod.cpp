#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod() {
    double R = -(2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x);
    a *= R;
}