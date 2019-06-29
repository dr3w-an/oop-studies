#include <iostream>
#include <set>

class Student {
    protected:
        std::string last_name;
        std::string first_name;
        std::string middle_name;
        std::string group;
        unsigned int scholarship = 0;

    public:
        std::set<int> classes;

        Student() {};
        Student(std::string last_name, std::string first_name, std::string group):
            last_name(last_name), first_name(first_name), group(group)
        {}
        Student(std::string last_name, std::string first_name, std::string middle_name, std::string group):
            last_name(last_name), first_name(first_name), middle_name(middle_name), group(group)
        {}

        void set_scholarship(const unsigned int scholarship) {
            this->scholarship = scholarship;
        }
        unsigned int get_scholarship() {
            return scholarship;
        }
        friend std::ostream &operator << (std::ostream &stream, Student &student) {
            stream << student.last_name << ' ' << student.first_name << ' ' << student.middle_name;
            return stream;
        }
};

class Headman: public Student {
    unsigned int scholarship_bonus = 0;

    public:
        int group_count;
        Student *group_list;

        Headman(std::string last_name, std::string first_name, std::string group):
            Student(last_name, first_name, group)
        {}
        Headman(std::string last_name, std::string first_name, std::string middle_name, std::string group):
            Student(last_name, first_name, middle_name, group)
        {}
        ~Headman() {
            delete[] group_list;
        }

        void set_scholarship_bonus(const unsigned int scholarship_bonus) {
            this->scholarship_bonus = scholarship_bonus;
        }
        unsigned int get_scholarship() {
            return scholarship + scholarship_bonus;
        }
        void mark_class(int class_number, bool attended[]) {
            for (int student = 0; student < group_count; student++)
                if (attended[student])
                    group_list[student].classes.insert(class_number);
        }
};

int main() {
    const std::string group = "ААБО-01-18";
    const int group_size = 4;
    const int class_number = 1;

    Headman headman("Коровяк", "Жанна", "Анатолиевна", group);
    headman.group_count = group_size;
    headman.group_list = new Student[group_size];
    headman.group_list[0] = Student("Кулишенко", "Филипп", "Викторович", group);
    headman.group_list[1] = Student("Титов", "Виктор", "Андреевич", group);
    headman.group_list[2] = Student("Якушева", "Юлия", group);
    headman.group_list[3] = headman;

    bool attended[group_size] = {true, false, true, false};
    headman.mark_class(class_number, attended);
    
    std::cout << "Занятие №" << class_number << " посетили студенты:\n";
    for (int student = 0; student < headman.group_count; student++)
        if (headman.group_list[student].classes.count(class_number) != 0)
            std::cout << headman.group_list[student] << '\n';

    return 0;
}
