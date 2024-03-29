#include "../include/FibonacciGenerator.hpp"
#include <iostream>

FibonacciGenerator::FibonacciGenerator(const std::string& name)
    : Task(name) {}

std::vector<int> FibonacciGenerator::fibRecursive(int n) const {
    std::vector<int> result;
    if (n < 1) {
        return result;
    }
    result.push_back(0);
    if (n == 1) {
        return result;
    }
    result.push_back(1);
    for (int i = 2; i < n; ++i) {
        int nextNumber = result[i - 1] + result[i - 2];
        result.push_back(nextNumber);
    }
    return result;
}

void FibonacciGenerator::execute() const {
    int n;
    std::cout << "How many Fibonacci numbers do you want to generate?" << std::endl;
    std::cin >> n;
    if (n < 1)
        std::cout << "Sorry, you have to give a number > 0." << std::endl;
    else 
        std::cout << "There you go:\n";
    if (getName() == "Fibonacci Generator Recursive") {
        for (auto& fib: fibRecursive(n)) {
            std::cout << fib << " ";
        }
    }
    else
        fibIterative(n);
    std::cout << std::endl;
}

void FibonacciGenerator::fibIterative(int n) const {
    int a = 0, b = 1;
    std::cout << " " << a;
    if (n == 1) {
        std::cout << std::endl;
        return;
    }
    std::cout << " " << b;
    for (int i = 2; i < n; ++i) {
        int nextNumber = a + b;
        std::cout << " " << nextNumber;
        a = b;
        b = nextNumber;
    }
}

#include <fstream>

void FibonacciGenerator::showCode() const {

    std::ifstream file {"../src/FibonacciGenerator.cpp"};

    if (file) {
        std::cout << "#include <iostream>" << std::endl;
        std::string line;
        int count = 1;
        while (std::getline(file, line)) {
            if (count>=8 && count<=22 && this->getName()=="Fibonacci Generator Recursive") {
                if (count == 8) std::cout << "#include <vector>\n\nstd::vector<int> fibRecursive(int n) {\n";
                std::cout << line << std::endl;
            }
            else if (count>=25 && count<=27) {
                if (count == 25) std::cout << "\nint main() {" << std::endl;
                std::cout << line << std::endl;
            }
            else if (count>=33 && count<=36 && this->getName()=="Fibonacci Generator Recursive") {
                std::cout << line << std::endl;
            }
            else if (count>=43 && count<=56 && this->getName()=="Fibonacci Generator Iterative") {
                std::cout << line << std::endl;
            }
            ++count;
        }
    }
    else
        std::cout << "Error loading file" << std::endl;
}