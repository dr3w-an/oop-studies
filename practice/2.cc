#include <iostream>
#include <math.h>

using namespace std;

void task_1(double a, double b) {
    double n, m;

    n = a >= b ? cbrt(a - b) : a * a + (a - b) / sin(a * b);

    if (n < b)
        m = (n + a) / (-b) + sqrt(pow(sin(a), 2) - cos(n));
    else if (n == b)
        m = b * b + tan(n * a);
    else
        m = pow(b, 3) + n * a * a;

    cout << "a = " << a << "; b = " << b << "; n = " << n << "; m = " << m << endl;
}


void task_2(double a, double b) {
    double z, t;

    z = a < b ? sqrt(abs(a * a - b * b)) : 1 - 2 * cos(a) * sin(b);

    if (z < b)
        t = cbrt(3 - z + a * a * b);
    else if (z == b)
        t = 1 - log(z) + cos(a * a * b);
    else
        t = 1 / cos(z * a);

    cout << "a = " << a << "; b = " << b << "; z = " << z << "; t = " << t << endl;
}


void task_3(double a, double b) {
    double y, t;

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
}


void task_4(double a, double x) {
    double y, t;

    y = a <= x ? a + log(x + a) : sqrt(abs(sin(a * x)));

    if (a > y)
        t = y / (a - x);
    else if (a == y)
        t = y / (a - x) + (a + x) / (y * y);
    else
        t = tan(a * x) + cos(2 * a * y);

    cout << "a = " << a << "; x = " << x << "; y = " << y << "; t = " << t << endl;
}


int main() {
    task_1( 4.8, -7.9);
    task_2(-0.6,  5.3);
    task_3( 4.6,  1.5);
    task_4( 3.5, -0.7);

    return 0;
}
