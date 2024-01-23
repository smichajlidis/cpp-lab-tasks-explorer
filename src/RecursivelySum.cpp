#include "../include/RecursivelySum.hpp"
#include <iostream>

RecursivelySum::RecursivelySum(const std::string& name)
    : Task(name) {}

int RecursivelySum::recFunction(int n) const {
    if (n == 0)
        return 0;
    else
        return n + recFunction(n - 1);
}

void RecursivelySum::execute() const {
    int sum = recFunction(100);
    std::cout << "The sum of numbers from 1 to 100 is: " << sum << std::endl;
}

#include <fstream>

void RecursivelySum::showCode() const {

    std::ifstream file {"../src/RecursivelySum.cpp"};

    if (file) {

        std::cout << "#include <iostream>\n" << std::endl;

        std::string line;
        int count = 1;
        while (std::getline(file, line)) {
            if (count>=8 && count<=12) {
                if (count == 8) std::cout << "int recFunction(int n) {" << std::endl;
                std::cout << line << std::endl;
            }
            else if (count>=15 && count<=17) {
                if (count == 15) std::cout << "\nint main() {" << std::endl;
                std::cout << line << std::endl;
            }
            ++count;
        }
    }
    else
        std::cout << "Error loading file" << std::endl;
}