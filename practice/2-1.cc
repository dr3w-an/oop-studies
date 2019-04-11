#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a, b, n, m;

    cout << "Введите два числа: ";
    cin >> a;
    cin >> b;

    n = a >= b ? cbrt(a - b) : a * a + (a - b) / sin(a * b);

    if (n < b)
        m = (n + a) / (-b) + sqrt(pow(sin(a), 2) - cos(n));
    else if (n == b)
        m = b * b + tan(n * a);
    else
        m = pow(b, 3) + n * a * a;

    cout << "a = " << a << "; b = " << b << "; n = " << n << "; m = " << m << endl;

    return 0;
}
