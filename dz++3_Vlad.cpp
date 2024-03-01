#include <iostream>
#include <fstream>
#include <vector>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмен значениями
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int MAX_SIZE = 1000; // Максимальный размер массива
    int numbers[MAX_SIZE]; // Массив для хранения чисел из файла
    int count = 0; // Счетчик чисел

    std::ifstream inputFile("f1.txt"); // Открытие файла для чтения
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file f1.txt\n";
        return 1;
    }

    int num;
    while (inputFile >> num) {
        numbers[count++] = num; // Чтение чисел из файла и добавление в массив
    }

    inputFile.close(); // Закрытие файла f1.txt

    bubbleSort(numbers, count); // Сортировка чисел пузырьком

    std::ofstream outputFile("f2.txt"); // Открытие файла для записи
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file f2.txt\n";
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        outputFile << numbers[i] << "\n"; // Запись отсортированных чисел в файл f2.txt
    }

    outputFile.close(); // Закрытие файла f2.txt

    std::cout << "Numbers sorted and saved to f2.txt successfully.\n";

    return 0;
}
