#include <iostream>
#include <math.h>

class Complex {
    public:
        double real;
        double imag;

        Complex() {};
        Complex(Complex &comp) {
            real = comp.real;
            imag = comp.imag;
        };
        Complex(double real, double imag):
            real(real), imag(imag)
        {}
        ~Complex() {};

        double abs() {
            return sqrt(pow(real, 2) + pow(imag, 2));
        };

        double argument() {
            if (real > 0)
                return atan(imag / real);
            else if (real < 0)
                return (imag >= 0 ? M_PI : -M_PI) + atan(imag / real);
            else
                return (imag > 0 ? M_PI / 2 : -M_PI / 2);
        };
};

int main() {
    double real, imag;
    std::cout << "Введите действительную часть комплексного числа: ";
    std::cin >> real;
    std::cout << "Введите мнимую часть комплексного числа: ";
    std::cin >> imag;
    Complex comp(real, imag);

    std::cout << "Модуль комплексного числа: " << comp.abs() << "\n"
              << "Аргумент комплексного числа: " << comp.argument() << std::endl;
    return 0;
}
