#include <iostream>
#include <math.h>

class Vector {
    public:
        double x, y;

        Vector() {};
        Vector(Vector &vector) {
            x = vector.x;
            y = vector.y;
        };
        Vector(double x, double y):
            x(x), y(y)
        {}
        ~Vector() {};

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

        Vector &operator = (Vector &vector) {
            x = vector.x;
            y = vector.y;
            return *this;
        }
        Vector &operator ++ () {
            x++;
            y++;
            return *this;
        }
        Vector &operator -- () {
            x--;
            y--;
            return *this;
        }
        bool operator == (Vector &vector) {
            return x == vector.x && y == vector.y;
        }
        bool operator != (Vector &vector) {
            return x != vector.x || y != vector.y;
        }
        friend std::istream &operator >> (std::istream &stream, Vector &vector) {
            stream >> vector.x;
            stream >> vector.y;
            return stream;
        }
        friend std::ostream &operator << (std::ostream &stream, const Vector &vector) {
            stream << '(' << vector.x << ", " << vector.y << ')';
            return stream;
        }
};

int main() {
    Vector first_vector, second_vector;
    std::cout << "Введите абсциссу и ординату первого вектора: ";
    std::cin >> first_vector;
    std::cout << "Введите абсциссу и ординату второго вектора: ";
    std::cin >> second_vector;

    ++first_vector;
    std::cout << "Инкрементированный первый вектор: " << first_vector << '\n';
    --first_vector;
    std::cout << "Векторы равны: " << (first_vector == second_vector ? "да" : "нет") << '\n';
    std::cout << "Векторы неравны: " << (first_vector != second_vector ? "да" : "нет") << '\n';
    return 0;
}
