#include <iostream>
#include <iomanip>


class Property {
    protected:
        double worth;
        Property(double w): worth(w) {}

    public:
        virtual ~Property() {}
        virtual double tax() = 0;
};

class Appartment: public Property {
    public:
        Appartment(double w): Property(w) {}
        double tax() { return worth / 1000; }
};

class Car: public Property {
    public:
        Car(double w): Property(w) {}
        double tax() { return worth / 200; }
};

class CountryHouse: public Property {
    public:
        CountryHouse(double w): Property(w) {}
        double tax() { return worth / 500; }
};


int main() {
    Property *properties[7];

    properties[0] = new Appartment(1000000.00);
    properties[1] = new Appartment(3000000.50);
    properties[2] = new Appartment(8001530.50);
    properties[3] = new Car(1000000.00);
    properties[4] = new Car(8001530.50);
    properties[5] = new CountryHouse(1000000.00);
    properties[6] = new CountryHouse(8001530.50);

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    for (int i = 0; i < 7; i++) {
        std::cout << "Налог на имущество " << i + 1 << ": "
                  << properties[i]->tax() << std::endl;
        delete properties[i];
    }

    return 0;
}
