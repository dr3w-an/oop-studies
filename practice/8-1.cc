#include <fstream>
#include <iostream>

int main() {
    std::ifstream file;
    std::string word;

    file.open("8-1.txt");
    while (file >> word) {
        std::cout << word << std::endl;
    }
    file.close();

    return 0;
}
