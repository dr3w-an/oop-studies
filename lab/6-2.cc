#include <iostream>

class Alive {
    public:
        float height;
        float weight;

        Alive(float height, float weight):
            height(height), weight(weight)
        {};
};

class Animal: public Alive {
    protected:
        std::string name;

    public:
        Animal(float height, float weight, std::string name):
            Alive(height, weight), name(name)
        {}
        void make_sound() {}
};

class Fish: public Animal {
    public:
        Fish(float height, float weight, std::string name):
            Animal(height, weight, name)
        {}
};

class Bird: public Animal {
    public:
        Bird(float height, float weight, std::string name):
            Animal(height, weight, name)
        {}
        void make_sound() {
            std::cout << name << " (" << height << " sm, " << weight << " kg): Tweet" << std::endl;
        }
};

int main() {
    Fish fish(60, 1.3, "Salmon");
    fish.make_sound();
    Bird bird(15, 0.035, "Sparrow");
    bird.make_sound();
    return 0;
}
