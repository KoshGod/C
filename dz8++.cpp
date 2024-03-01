#include <iostream>
#include <list>

void doubleValueOccurrences(std::list<int>& myList, int value) {
    auto it = myList.begin();
    while (it != myList.end()) {
        if (*it == value) {
            it = myList.insert(std::next(it), *it);
            std::advance(it, 2);
        } else {
            ++it;
        }
    }
}

int main() {
    std::list<int> myList = {1, 2, 3, 2, 4, 2, 5};
    int valueToDouble = 2;

    std::cout << "Original list: ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    doubleValueOccurrences(myList, valueToDouble);

    std::cout << "List after doubling occurrences of " << valueToDouble << ": ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
