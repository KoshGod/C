#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream inputFile("f1.txt");
    std::ofstream outputFile("f2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    std::string text;
    inputFile >> text;

    std::random_shuffle(text.begin(), text.end());

    outputFile << text;

    inputFile.close();
    outputFile.close();

    return 0;
}
