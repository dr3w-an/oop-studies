#include <fstream>
#include <iostream>

int main() {
    std::ofstream file;
    std::string line;

    file.open("8-2.txt");
    getline(std::cin, line);
    while (line.length() > 0) {
        file << line << std::endl;
        getline(std::cin, line);
    }
    file.close();

    return 0;
}
