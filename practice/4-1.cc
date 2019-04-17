#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


double *allocate_memory(double *arr, int size) {
    return (double *)malloc(size * sizeof(double));
}

void fill(double *arr, int size) {
    cout << "Введите массив: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void display(double *arr, int size) {
    cout << arr[0];
    for (int i = 1; i < size; i++) {
        cout << ' ' << arr[i];
    }
    cout << endl;
}

void free_memory(double *arr) {
    free(arr);
}

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    if (size <= 0) return 1;

    double *arr = allocate_memory(arr, size);
    fill(arr, size);
    display(arr, size);
    free_memory(arr);

    return 0;
}
