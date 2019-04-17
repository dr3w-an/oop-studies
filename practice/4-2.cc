#define SIZE 12

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void function(int *arr) {
    for (int i = 0; i < SIZE - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
}

int main() {
    int *arr = (int *)malloc(SIZE * sizeof(int));

    cout << "Введите массив: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    function(arr);
    cout << arr[0];
    for (int i = 1; i < SIZE; i++) {
        cout << ' ' << arr[i];
    }
    cout << endl;

    free(arr);
    return 0;
}
