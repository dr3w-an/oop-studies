#include <iostream>
#include <math.h>

class Vector {
    public:
        double x, y;

        double abs() {
            return sqrt(pow(x, 2) + pow(y, 2));
        }

        Vector add(Vector vector) {
            Vector result;
            result.x = x + vector.x;
            result.y = y + vector.y;
            return result;
        }

        Vector substract(Vector vector) {
            Vector result;
            result.x = x - vector.x;
            result.y = y - vector.y;
            return result;
        }
};

int main() {
    Vector first_vector;
    std::cout << "Введите абсциссу первого вектора: ";
    std::cin >> first_vector.x;
    std::cout << "Введите ординату первого вектора: ";
    std::cin >> first_vector.y;

    Vector second_vector;
    std::cout << "Введите абсциссу второго вектора: ";
    std::cin >> second_vector.x;
    std::cout << "Введите ординату второго вектора: ";
    std::cin >> second_vector.y;

    Vector sum = first_vector.add(second_vector);
    Vector dif = first_vector.substract(second_vector);

    std::cout << "Модуль первого вектора: " << first_vector.abs() << '\n'
              << "Модуль второго вектора: " << second_vector.abs() << '\n'
              << "Сумма векторов: (" << sum.x << ", " << sum.y << ")\n"
              << "Разность векторов: (" << dif.x << ", " << dif.y << ')' << std::endl;

    return 0;
}
