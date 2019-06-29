#include <iostream>

class Animal {
    protected:
        std::string name;

    public:
        Animal(std::string name):
            name(name)
        {}
        void make_sound() {}
};

class Cat: public Animal {
    public:
        Cat(std::string name): Animal(name) {};
        void make_sound() {
            std::cout << name << ": " << "Meow" << std::endl;
        };
};

class Dog: public Animal {
    public:
        Dog(std::string name): Animal(name) {};
        void make_sound() {
            std::cout << name << ": " << "Woof" << std::endl;
        };
};

int main() {
    Cat cat("Max");
    cat.make_sound();
    Dog dog("Sam");
    dog.make_sound();
    return 0;
}
