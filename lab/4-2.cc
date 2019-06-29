#include <iostream>

class Tiles {
    public:
        std::string brand;
        int size_h;
        int size_w;
        int price;

        Tiles() {};
        Tiles(Tiles &tiles) {
            brand = tiles.brand;
            size_h = tiles.size_h;
            size_w = tiles.size_w;
            price = tiles.price;
        };
        Tiles(std::string brand, int size_h, int size_w, int price):
            brand(brand), size_h(size_h), size_w(size_w), price(price)
        {}
        ~Tiles() {};

        void getData() {
            std::cout << "Бренд: " << brand << '\n'
                      << "Высота: " << size_h << '\n'
                      << "Ширина: " << size_w << '\n'
                      << "Цена: " << price << std::endl;
        };
};

int main() {
    std::string brand;
    int size_h;
    int size_w;
    int price;

    std::cout << "Введите бренд первого кафеля: ";
    std::cin >> brand;
    std::cout << "Введите высоту первого кафеля: ";
    std::cin >> size_h;
    std::cout << "Введите ширину первого кафеля: ";
    std::cin >> size_w;
    std::cout << "Введите цену первого кафеля: ";
    std::cin >> price;
    auto *first_tiles = new Tiles(brand, size_h, size_w, price);
    std::cout << std::endl;

    Tiles second_tiles = *first_tiles;
    std::cout << "Введите бренд второго кафеля: ";
    std::cin >> second_tiles.brand;
    std::cout << "Введите высоту второго кафеля: ";
    std::cin >> second_tiles.size_h;
    std::cout << "Введите ширину второго кафеля: ";
    std::cin >> second_tiles.size_w;
    std::cout << "Введите цену второго кафеля: ";
    std::cin >> second_tiles.price;
    std::cout << std::endl;

    std::cout << "Данные первого кафеля\n";
    first_tiles->getData();
    delete first_tiles;
    std::cout << "\nДанные второго кафеля\n";
    second_tiles.getData();

    return 0;
}
