#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void fill(int **arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            arr[i][j] = rand() % 40 + 10;  // Случайное число от 10 до 50
        }
    }
}

void display(int **arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << arr[i][columns - 1] << endl;
    }
}

int main() {
    int rows, columns;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> columns;

    int **arr = new int *[rows];

    srand(time(NULL));

    fill(arr, rows, columns);
    display(arr, rows, columns);

    return 0;
}
