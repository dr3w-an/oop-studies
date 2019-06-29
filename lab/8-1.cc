#include <iostream>
#include <vector>

struct Student {
    std::string last_name;
    std::string first_name;
    std::string middle_name;
    std::string group;
    unsigned int scholarship = 0;
};

int main() {
    std::vector<Student> students;
    students.push_back({"Зуев", "Павел", "Владимирович", "АВБО-02-17", 2871});
    students.push_back({"Орехов", "Виктор", "Фёдорович", "АВБО-02-17", 3995});
    students.push_back({"Артемьев", "Фёдор", "Владимирович", "БГБО-03-16", 1639});
    std::cout << "Данные о студентах:\n";
    for (auto student: students) {
        std::cout << student.last_name << ' ' << student.first_name << ' ' << student.middle_name
                  << " (" << student.group << ") - " << student.scholarship << " р." << std::endl;
    }
    return 0;
}
