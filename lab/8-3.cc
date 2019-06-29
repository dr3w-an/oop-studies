#include <iostream>
#include <queue>

struct Auto {
    std::string number;
    std::string brand;
    std::string phone;
    unsigned int price;
};

int main() {
    std::queue<Auto> wash;
    wash.push({"Х049ТР", "Audi", "86121611490", 300});
    wash.push({"А559ЕМ", "BMW", "84333601493", 600});
    wash.push({"У697РТ", "Toyota", "81449581187", 300});
    std::cout << "Автомобили в очереди:\n";
    while (!wash.empty()) { 
        auto automobile = wash.front();
        std::cout << automobile.brand << ' ' << automobile.number << " - " << automobile.price << " р." << std::endl; 
        wash.pop(); 
    } 
    return 0;
}
