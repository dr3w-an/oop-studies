#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double a, b, y, t;

    cout << "Введите два числа: ";
    cin >> a;
    cin >> b;

    y = a <= b ?
        ((a - b) / (a + b)) * ((a + b) / (a * a - a * b + b * b)) :
        a + log(b * b);

    if (y == b)
        t = (2 * y + sqrt(y * y - a)) / (2 * b - sqrt(a * a - y));
    else if (y < b)
        t = pow(sin(y), 2) + 1 / tan(a - b);
    else
        t = cbrt(y * sin(a)) + 1 / sqrt(y * cos(b));

    cout << "a = " << a << "; b = " << b << "; y = " << y << "; t = " << t << endl;

    return 0;
}
