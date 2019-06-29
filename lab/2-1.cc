#include <iostream>

int sum(int a, int b) {
    return a + b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mul(int a, int b) {
    return a * b;
}

int fold(int *array, unsigned int size, int (*func)(int, int)) {
    int result = func(array[0], array[1]);
    for (unsigned int i = 2; i < size; i++)
        result = func(result, array[i]);
    return result;
}

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int array[size];
    std::cout << "Введите " << size << " целых чисел: ";
    for (int i = 0; i < size; i++)
        std::cin >> array[i];

    int operation;
    std::cout << "Номера операций:\n"
              << "1 - найти сумму чисел\n"
              << "2 - найти максимальное число\n"
              << "3 - найти произведение чисел.\n"
              << "Введите номер операции: ";
    std::cin >> operation;

    int (*func)(int, int);
    switch (operation) {
        case 1: func = sum; break;
        case 2: func = max; break;
        case 3: func = mul; break;
        default:
            std::cerr << "Неизвестная операция." << std::endl;
            return 1;
    }
    std::cout << fold(array, size, func) << std::endl;
    return 0;
}
