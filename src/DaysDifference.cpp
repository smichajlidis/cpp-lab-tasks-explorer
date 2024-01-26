#include "../include/DaysDifference.hpp"
#include <iostream>
#include <numeric>

DaysDifference::DaysDifference(const std::string& name)
    : Task(name) {}

void DaysDifference::execute() const {

    int day1, month1, year1;
    int day2, month2, year2;

    std::cout << "Enter the first date (day month year): ";
    std::cin >> day1 >> month1 >> year1;

    std::cout << "Enter the second date (day month year): ";
    std::cin >> day2 >> month2 >> year2;

    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int days1 = day1 + year1 * 365 + (year1 / 4) - (year1 / 100) + (year1 / 400) + std::accumulate(daysInMonth, daysInMonth + month1, 0);
    int days2 = day2 + year2 * 365 + (year2 / 4) - (year2 / 100) + (year2 / 400) + std::accumulate(daysInMonth, daysInMonth + month2, 0);

    int daysDifference;

    if (days2 > days1) {
        daysDifference = days2 - days1;
    } else {
        daysDifference = days1 - days2;
    }

    std::cout << "Days between the two dates: " << daysDifference << " days" << std::endl;

}

#include <fstream>

void DaysDifference::showCode() const {

    std::ifstream file {"../src/DaysDifference.cpp"};

    if (file) {
        std::string line;
        int count = 1;
        while (std::getline(file, line)) {
            if (count == 2 || count == 3) {
                std::cout << line << std::endl;
            }
            else if (count>=9 && count<=34) {
                if (count == 10) std::cout << "\nint main() {" << std::endl;
                std::cout << line << std::endl;
            }
            ++count;
        }
    }
    else
        std::cout << "Error loading file" << std::endl;
}