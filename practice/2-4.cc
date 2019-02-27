#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double a, x, y, t;

    cout << "Введите два числа: ";
    cin >> a;
    cin >> x;

    y = a <= x ? a + log(x + a) : sqrt(sin(a * x));

    if (a > y)
        t = y / (a - x);
    else if (a == y)
        t = y / (a - x) + (a + x) / (y * y);
    else
        t = tan(a * x) + cos(2 * a * y);

    cout << "a = " << a << "; x = " << x << "; y = " << y << "; t = " << t << endl;

    return 0;
}
