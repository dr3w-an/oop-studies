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
    Complex first_comp, second_comp;
    std::cout << "Введите действительную и мнимую часть первого комплексного числа: ";
    std::cin >> first_comp;
    std::cout << "Введите действительную и мнимую часть второго комплексного числа: ";
    std::cin >> second_comp;

    ++first_comp;
    std::cout << "Инкрементированное первое комплексное число: " << first_comp << '\n';
    --first_comp;
    std::cout << "Комплексные числа равны: " << (first_comp == second_comp ? "да" : "нет") << '\n';
    std::cout << "Комплексные числа неравны: " << (first_comp != second_comp ? "да" : "нет") << '\n';

    return 0;
}
