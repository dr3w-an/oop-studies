#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double a, b, z, t;

    cout << "Введите два числа: ";
    cin >> a;
    cin >> b;

    z = a < b ? sqrt(abs(a * a - b * b)) : 1 - 2 * cos(a) * sin(b);

    if (z < b)
        t = cbrt(3 - z + a * a * b);
    else if (z == b)
        t = 1 - log(z) + cos(a * a * b);
    else
        t = 1 / cos(z * a);

    cout << "a = " << a << "; b = " << b << "; z = " << z << "; t = " << t << endl;

    return 0;
}
