#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::string;

class Animal {
    string name;

    public:
        Animal(string n): name(n) {}
        void make_sound() {
            std::cout << name << ": " << get_sound() << std::endl;
        };

    protected:
        virtual string get_sound() = 0;
};

class Cat: public Animal {
    public:
        Cat(string n): Animal(n) {};
        string get_sound() { return "Meow"; }
};

class Dog: public Animal {
    public:
        Dog(string n): Animal(n) {};
        string get_sound() { return "Woof"; }
};

class Parrot: public Animal {
    std::vector<string> phrases = {"Screech", "Squawk"};

    public:
        Parrot(string n): Animal(n) {};

        void teach(string phrase) {
            phrases.push_back(phrase);
        }

        void teach(std::vector<string> addendum) {
            phrases.insert(phrases.end(), addendum.begin(), addendum.end());
        }

        string get_sound() {
            /* Use Mersenne Twister algorithm to create a uniform random
               distrubition of vector indexes to get any member of vector
               phrases with equal probability */
            std::random_device random_device;
            std::mt19937 engine{random_device()};
            std::uniform_int_distribution<int> dist(0, phrases.size() - 1);
            return phrases[dist(engine)];
        }
};

int main() {
    Cat cat("Leo");
    cat.make_sound();

    Dog dog("Ace");
    dog.make_sound();

    Parrot parrot("Rio");
    parrot.teach("Good bird");
    parrot.teach(std::vector<string> {"Hello", "How are you", "Good morning"});
    for (int i = 0; i < 5; i++) {
        parrot.make_sound();
    }

    return 0;
}
