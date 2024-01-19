#include "../include/FibonacciGenerator.hpp"
#include <iostream>

FibonacciGenerator::FibonacciGenerator(const std::string& name)
    : Task(name) {}

void FibonacciGenerator::execute() const {
    int n;
    std::cout << "How many Fibonacci numbers do you want to generate?" << std::endl;
    std::cin >> n;
    if (n < 1)
        std::cout << "Sorry, you have to give a number > 0." << std::endl;
    else 
        std::cout << "There you go:\n";
    if (getName() == "Fibonacci Generator Recursive")
        std::cout << "recursive code" << std::endl;
    else
        fibIterative(n);
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

    std::cout << std::endl;
}