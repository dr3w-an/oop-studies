#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "Как тебя зовут? ";
    getline(cin, name);
    cout << "Привет, " << name << "!\n";

    return 0;
}
