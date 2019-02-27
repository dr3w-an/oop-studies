#include <iostream>
#include <iomanip>
using namespace std;

struct book {
    string author;
    string title;
    string edition;
    int year;
    int quantity;

    void full_title(void) {
        cout << author << ". " << title;
        cout << " / " << edition << ", " << year << ".";
    }
};

struct work_hours {
    int start_hours;
    int start_minutes;
    int end_hours;
    int end_minutes;
};

struct library {
    string name;
    book *books;
    int books_count;
    string address;
    work_hours hours[7];

    void display() {
        cout << "Список книг:" << endl;
        list_books();
        cout << endl << "Адрес: " << address << endl;
        cout << endl << "Часы работы: " << endl;
        list_work_hours();
    }

    void list_books() {
        for (int i = 0; i < books_count; i++) {
            cout << i + 1 << ") ";
            books[i].full_title();
            cout << " (" << books[i].quantity << ")" << endl;
        }
    }

    void list_work_hours() {
        string weekdays[] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
        for (int i = 0; i < 7; i++) {
            cout << weekdays[i] << ". ";
            if (hours[i].start_hours < 0) {
                cout << "Выходной";
            } else {
                cout << hours[i].start_hours << ":" << setw(2) << setfill('0') << hours[i].start_minutes;
                cout << " - ";
                cout << hours[i].end_hours << ":" << setw(2) << setfill('0') << hours[i].end_minutes;
            }
            cout << endl;
        }
    }
};
