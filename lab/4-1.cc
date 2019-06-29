#include <iostream>

class Child {
    std::string name;
    std::string surname;
    int age;

    public:
        Child() {};
        Child(Child &child) {
            name = child.name;
            surname = child.surname;
            age = child.age;
        };
        Child(std::string name, std::string surname, int age):
            name(name), surname(surname), age(age)
        {}
        ~Child() {};

        void set_name(std::string name) {
            this->name = name;
        };
        void set_surname(std::string surname) {
            this->surname = surname;
        };
        void set_age(int age) {
            this->age = age;
        };
        void print() {
            std::cout << "Имя: " << name << '\n'
                      << "Фамилия: " << surname << '\n'
                      << "Возраст: " << age << std::endl;
        };
};

int main() {
    Child first_child;
    std::string first_child_name;
    std::string first_child_surname;
    int first_child_age;
    std::cout << "Введите имя первого ребёнка: ";
    std::cin >> first_child_name;
    first_child.set_name(first_child_name);
    std::cout << "Введите фамилию первого ребёнка: ";
    std::cin >> first_child_surname;
    first_child.set_surname(first_child_surname);
    std::cout << "Введите возраст первого ребёнка: ";
    std::cin >> first_child_age;
    first_child.set_age(first_child_age);
    std::cout << std::endl;

    Child second_child;
    std::string second_child_name;
    std::string second_child_surname;
    int second_child_age;
    std::cout << "Введите имя второго ребёнка: ";
    std::cin >> second_child_name;
    second_child.set_name(second_child_name);
    std::cout << "Введите фамилию второго ребёнка: ";
    std::cin >> second_child_surname;
    second_child.set_surname(second_child_surname);
    std::cout << "Введите возраст второго ребёнка: ";
    std::cin >> second_child_age;
    second_child.set_age(second_child_age);
    std::cout << std::endl;

    std::cout << "Данные первого ребёнка\n";
    first_child.print();
    std::cout << "\nДанные второго ребёнка\n";
    second_child.print();

    return 0;
}
