#include <iostream>


template <typename num>
void display_array(num *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << arr[size - 1] << std::endl;
}


template <typename num>
void swap(num *a, num *b) {
    num temp = *a;
    *a = *b;
    *b = temp;
}


template <typename num>
void bubble_sort(num *arr, int size) {
    num result[size];
    std::copy(arr, arr + size, result);

    bool unsorted = true;
    while (unsorted) {
        unsorted = false;
        for (int i = 0; i < size - 1; i++) {
            if (result[i] > result[i + 1]) {
                swap(&result[i], &result[i + 1]);
                unsorted = true;
            }
        }
    }

    display_array<num>(result, size);
}


template <typename num>
void selection_sort(num *arr, int size) {
    num result[size];
    std::copy(arr, arr + size, result);

    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (result[j] < result[min]) min = j;
        }
        if (min != i) {
            swap(&result[i], &result[min]);
        }
    }

    display_array<num>(result, size);
}


template <typename num>
void insertion_sort(num *arr, int size) {
    num result[size];
    std::copy(arr, arr + size, result);

    num pivot;
    int j;

    for (int i = 1; i < size; i++) {
        pivot = result[i];
        j = i - 1;

        while (j >= 0 && result[j] > pivot) {
            result[j + 1] = result[j];
            j--;
        }
        result[j + 1] = pivot;
    }

    display_array<num>(result, size);
}


int main() {
    int int_size;
    std::cout << "Введите размер массива целых чисел: ";
    std::cin >> int_size;
    
    int int_array[int_size];
    std::cout << "Введите массив целых чисел: ";
    for (int i = 0; i < int_size; i++) {
        std::cin >> int_array[i];
    }

    int double_size;
    std::cout << "Введите размер массива чисел с плавающей точкой: ";
    std::cin >> double_size;
    
    double double_array[double_size];
    std::cout << "Введите массив чисел с плавающей точкой: ";
    for (int i = 0; i < double_size; i++) {
        std::cin >> double_array[i];
    }
    std::cout << '\n';

    std::cout << "Сортировка пузырьком\n";
    bubble_sort<int>(int_array, int_size);
    bubble_sort<double>(double_array, double_size);

    std::cout << "Сортировка выбором\n";
    selection_sort<int>(int_array, int_size);
    selection_sort<double>(double_array, double_size);

    std::cout << "Сортировка вставкой\n";
    insertion_sort<int>(int_array, int_size);
    insertion_sort<double>(double_array, double_size);

    return 0;
}
