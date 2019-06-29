#include <iostream>
#include <math.h>
#include <list>

class Complex {
    public:
        double real;
        double imag;

        Complex() {};
        Complex(const Complex &comp) {
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

        Complex &operator = (Complex &comp) {
            real = comp.real;
            imag = comp.imag;
            return *this;
        }
        Complex &operator ++ () {
            real++;
            imag++;
            return *this;
        }
        Complex &operator -- () {
            real--;
            imag--;
            return *this;
        }
        bool operator == (Complex &comp) {
            return real == comp.real && imag == comp.imag;
        }
        bool operator != (Complex &comp) {
            return real != comp.real || imag != comp.imag;
        }
        friend std::istream &operator >> (std::istream &stream, Complex &comp) {
            stream >> comp.real;
            stream >> comp.imag;
            return stream;
        }
        friend std::ostream &operator << (std::ostream &stream, const Complex &comp) {
            stream << '(' << comp.real << ", " << comp.imag << ')';
            return stream;
        }
};

int main() {
    std::list<Complex> complexes;
    Complex zero(0, 0);
    Complex comp;
    std::cout << "Вводите действительную и мнимую часть комплексных чисел:\n";
    std::cin >> comp;
    while (comp != zero) {
        complexes.push_back(comp);
        std::cin >> comp;
    }
    for (auto comp: complexes)
        std::cout << "Аргумент числа " << comp << ": " << comp.argument() << std::endl;
    return 0;
}
