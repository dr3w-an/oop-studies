#include <iostream>

class Human {
    std::string surname;
    std::string name;
    std::string midname;
    int age;

    public:
        Human() {};
        Human(std::string s, std::string n, std::string m, int a):
            surname(s), name(n), midname(m), age(a)
        {}
        virtual void print() {
            std::cout << "Surname: " << surname << "\n"
                      << "Name: " << name << "\n"
                      << "Midname: " << midname << "\n"
                      << "Age: " << age << "\n";
        };
        virtual ~Human() {};
};


class Student: Human {
    bool on_lesson;

    public:
        Student() {};
        Student(std::string s, std::string n, std::string m, int a, bool l):
            Human(s, n, m, a), on_lesson(l)
        {}
        void print() {
            Human::print();
            std::cout << "Student is ";
            if (!on_lesson) std::cout << "not ";
            std::cout << "on lesson" << "\n";
        }
        ~Student() {};
};


class Boss: Human {
    int number_of_workers;

    public:
        Boss();
        Boss(std::string s, std::string n, std::string m, int a, int w):
            Human(s, n, m, a), number_of_workers(w)
        {}
        void print() {
            Human::print();
            std::cout << "Number of workers: " << number_of_workers << "\n";
        };
        ~Boss() {};
};


int main() {
    auto student = Student("Кудряшов", "Богдан", "Виталиевич", 20, true);
    student.print();
    std::cout << std::endl;
    auto boss = Boss("Беляков", "Валерий", "Михайлович", 31, true);
    boss.print();

    return 0;
}
