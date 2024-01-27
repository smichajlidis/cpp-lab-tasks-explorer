#include "../include/ArrayAddition.hpp"
#include <iostream>

ArrayAddition::ArrayAddition(const std::string& name)
    : Task(name) {}

void ArrayAddition::execute() const {

    int size;

    std::cout << "How many additions do you want? ";
    std::cin >> size;

    int num1[size];
    int num2[size];

    std::cout << "Enter the first " << size << " numbers: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> num1[i];
    }

    std::cout << "Enter the second " << size << " numbers: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> num2[i];
    }

    std::cout << "\nResult: \n" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << num1[i] << " + " << num2[i] << " = " << num1[i]+num2[i] << std::endl;
    }

}

#include <fstream>

void ArrayAddition::showCode() const {

    std::ifstream file {"../src/ArrayAddition.cpp"};

    if (file) {
        std::string line;
        int count = 1;
        while (std::getline(file, line)) {
            if (count==2) {
                std::cout << line << std::endl;
            }
            else if (count>=8 && count<=32) {
                if (count == 8) std::cout << "\nint main() {" << std::endl;
                std::cout << line << std::endl;
            }
            ++count;
        }
    }
    else
        std::cout << "Error loading file" << std::endl;
}