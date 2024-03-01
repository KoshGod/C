#include <iostream>
#include <string>

void calculateLetterFrequency(const std::string& str) {
    int frequencyMap[26] = { 0 };

    for (char c : str) {
        if (std::isalpha(c) && std::islower(c)) {
            int index = c - 'a';
            frequencyMap[index]++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (frequencyMap[i] > 0) {
            char letter = 'a' + i;
            std::cout << letter << ": " << frequencyMap[i] << std::endl;
        }
    }
}

int main() {
    std::string inputString = "Hello, World!";
    calculateLetterFrequency(inputString);

    return 0;
}
