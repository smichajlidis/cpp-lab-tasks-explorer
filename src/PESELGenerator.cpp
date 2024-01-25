#include "../include/PESELGenerator.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

PESELGenerator::PESELGenerator(const std::string& name)
    : Task(name) {}

void PESELGenerator::execute() const {
      std::srand(static_cast<unsigned int>(std::time(0)));

    int year, month, day;
    std::cout << "Enter the year of birth (1900-2099): ";
    std::cin >> year;

    std::cout << "Enter the month of birth (1-12): ";
    std::cin >> month;

    std::cout << "Enter the day of birth (1-31): ";
    std::cin >> day;

    int randomDigits = std::rand() % 100000;

    int pesel[11];
    pesel[0] = (year % 100) / 10;
    pesel[1] = (year % 100) % 10;
    pesel[2] = month / 10;
    pesel[3] = month % 10;
    pesel[4] = day / 10;
    pesel[5] = day % 10;

    for (int i = 6; i < 11; ++i) {
        pesel[i] = randomDigits % 10;
        randomDigits /= 10;
    }

    std::cout << "Generated PESEL number: ";
    for (int i = 0; i < 11; ++i) {
        std::cout << pesel[i];
    }
    std::cout << std::endl;
}

#include <fstream>

void PESELGenerator::showCode() const {

    std::ifstream file {"../src/PESELGenerator.cpp"};

    if (file) {
        std::string line;
        int count = 1;
        while (std::getline(file, line)) {
            if (count>=2 && count<=4) {
                std::cout << line << std::endl;
            }
            else if (count>=10 && count<=42) {
                if (count == 10) std::cout << "\nint main() {" << std::endl;
                std::cout << line << std::endl;
            }
            ++count;
        }
    }
    else
        std::cout << "Error loading file" << std::endl;
}