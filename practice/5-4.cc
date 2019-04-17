#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;


class Number {
    // Класс числа, который может использоваться как int или double
    // в зависимости от равенства нулю дробной части

    private:
        int integer;     // Целая часть
        double decimal;  // Дробная часть

        void normalize() {
            if (decimal > 1) {
                double right;
                decimal = modf(decimal, &right);
                integer += (int) right;
            }
        }

    public:
        Number(double number) {
            double whole;
            decimal = modf(number, &whole);
            integer = (int) whole;
        }

        Number(string line) {
            stringstream ss(line);
            if (line.find('.') == string::npos) {
                ss >> integer;
                decimal = 0.0;
            } else {
                double number;
                ss >> number;
                *this = Number(number);
            }
        }

        Number operator += (Number const &number) {
            this->integer += number.integer;
            if (number.decimal)
                this->decimal += number.decimal;
            normalize();
            return *this;
        }

        Number operator -= (Number const &number) {
            this->integer -= number.integer;
            if (number.decimal)
                this->decimal -= number.decimal;
            normalize();
            return *this;
        }

        Number operator *= (Number const &number) {
            double operand = number.integer + number.decimal;
            this->integer *= operand;
            this->decimal *= operand;
            normalize();
            return *this;
        }

        Number operator /= (Number const &number) {
            double operand = number.integer + number.decimal;
            this->decimal = (integer + decimal) / operand;
            this->integer = 0;
            normalize();
            return *this;
        }

        string format() {
            ostringstream oss;
            if (decimal)
                oss << integer + decimal;
            else
                oss << integer;
            return oss.str();
        }
};


int main() {
    string line;
    cout << "Введите число и на следующей строке оператор и операнд:\n ";
    getline(cin, line);
    Number number(line);
    char operation;

    while (true) {
        cin >> operation;
        getline(cin, line);
        Number operand(line);
        bool warn = false;
        switch (operation) {
            case '=': number =  operand; break;
            case '+': number += operand; break;
            case '-': number -= operand; break;
            case '*': number *= operand; break;
            case '/': number /= operand; break;
            default:  warn = true;       break;
        }
        if (operation != '=') {
            cout << '=' << number.format();
            if (warn) cout << " (Неизвестный оператор)";
            cout << endl;
        }
    }

    return 0;
}
