/* Класс – персональный компьютер (ПК). Параметры (поля класса): название
   процессора, тактовая частота. Статус доступа всех полей private. Класс
   включает: конструктор, при необходимости функции доступа к полям, функцию
   печати параметров. Вывести на печать параметры всех компьютеров в порядке
   невозрастания тактовой частоты. */

#include <iostream>
#include <algorithm>

class PersonalComputer {
    std::string cpu_;
    int frequency_;

    public:
        PersonalComputer() {};
        PersonalComputer(std::string cpu, int frequency):
            cpu_(cpu), frequency_(frequency)
        {};
        virtual ~PersonalComputer() = default;

              std::string& cpu()       { return cpu_; }        // Setter
        const std::string& cpu() const { return cpu_; }        // Getter

              int& frequency()         { return frequency_; }  // Setter
        const int& frequency() const   { return frequency_; }  // Getter

        void print() {
            std::cout << "Процессор " << cpu_
                      << " (" << frequency_ << " МГц)"
                      << std::endl;
        }
};


bool compare_frequencies(PersonalComputer first_pc, PersonalComputer second_pc) {
    return (first_pc.frequency() >= second_pc.frequency());
}


int main() {
    int amount;

    std::cout << "Введите количество ПК: ";
    std::cin >> amount;
    std::cout << '\n';

    PersonalComputer computers[amount]; 

    for (int i = 0; i < amount; i++) {
        std::cout << '(' << i + 1 << '/' << amount << ") Название процессора: ";
        std::getline(std::cin >> std::ws, computers[i].cpu());
        std::cout << '(' << i + 1 << '/' << amount << ") Частота процессора (в МГц): ";
        std::cin >> computers[i].frequency();
        std::cout << '\n';
    }

    std::sort(computers, computers + amount, compare_frequencies);

    std::cout << std::endl;
    for (int i = 0; i < amount; i++) {
        std::cout << i + 1 << ". ";
        computers[i].print();
    }

    return 0;
}
