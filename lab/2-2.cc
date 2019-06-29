#include <iostream>
#include <stdlib.h>

void print_array(int *array, int size) {
    if (size > 0) {
        std::cout << array[0];
        for (int i = 1; i < size; i++)
            std::cout << ' ' << array[i];
    }
    std::cout << std::endl;
}

void invert_array(int *array, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

void sort_not_descending(int *array, int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        int element = array[i];
        for (j = i - 1; j >= 0 && array[j] >= element; j--)
            array[j + 1] = array[j];
        array[j + 1] = element;
    }
}

void sort_not_ascending(int *array, int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        int element = array[i];
        for (j = i - 1; j >= 0 && array[j] <= element; j--)
            array[j + 1] = array[j];
        array[j + 1] = element;
    }
}

void (*action(int *array, int size))(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];

    if (sum == array[0])
        return invert_array;
    else if (sum > array[0])
        return sort_not_descending;
    else
        return sort_not_ascending;
}

int main() {
    const int size = 10;
    int array[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 21 - 10;

    print_array(array, size);
    action(array, size)(array, size);
    print_array(array, size);

    return 0;
}
