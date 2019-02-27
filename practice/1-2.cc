#include <iostream>
using namespace std;

int main() {
    float number_1;
    float number_2;
    cout << "Введите два числа: ";
    cin >> number_1;
    cin >> number_2;

    char operation;
    float result;
    while (1) {
        cout << "Введите операцию: ";
        cin >> operation;
        switch (operation) {
            case '+':
                result = number_1 + number_2;
                break;
            case '-':
                result = number_1 - number_2;
                break;
            default:
                cout << "Неизвестная операция. Доступные операции: '+', '-'.\n";
                continue;
        }
        break;
    }

    cout << number_1 << operation << number_2 << "=" << result << "\n";
    return 0;
}
