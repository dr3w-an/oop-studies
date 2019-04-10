#include <iostream>
#include "3-1.cc"
using namespace std;


book rtu_books[] = {
    {"Страуструп Бьёрн", "Дизайн и эволюция C++", "СПб.: Питер", 2006, 4},
    {"T. H. Cormen, C. E. Leiserson, R. L. Rivest, C. Stein", "Introduction to Algorithms", "Massachusetts: The MIT Press", 2004, 1}
};


book rsl_books[] = {
    {"Борис Пастернак", "Доктор Живаго", "Эксмо", 2010, 14},
    {"Евгений Замятин", "Мы", "Эксмо", 2016, 53},
    {"Александр Пушкин", "Дубровский", "Эксмо", 2013, 58}
};


library libraries[] = {
    {"РТУ", rtu_books, sizeof(rtu_books) / sizeof(rtu_books[0]), "пр. Вернадского, 78",
        {
            {10, 0, 17, 30},  // Начало работы в 10:00, конец в 17:30
            {10, 0, 17, 30},
            {10, 0, 18, 30},
            {10, 0, 17, 30},
            {10, 0, 18, 30},
            {10, 0, 14, 30},
            {-1, 0, 0, 0}     // Выходной день если часы начала работы меньше 0
        }
    },
    {"РГБ", rsl_books, sizeof(rsl_books) / sizeof(rsl_books[0]), "ул. Воздвиженка, 3/5",
        {
            {-1, 0, 0, 0},   // Выходной день
            {9, 0, 20, 0},
            {9, 0, 20, 0},
            {9, 0, 20, 0},
            {9, 0, 20, 0},
            {9, 0, 20, 0},
            {9, 0, 20, 0}
        }
    }
};


int main() {
    string name;
    cout << "Введите название библиотеки: ";
    cin >> name;
    cout << endl;

    int library_quantity = sizeof(libraries) / sizeof(libraries[0]);
    for (int i = 0; i < library_quantity; i++) {
        if (libraries[i].name == name) {
            libraries[i].display();
            return 0;
        }
    }

    cout << "Библиотека не найдена." << endl;
    return 1;
}
