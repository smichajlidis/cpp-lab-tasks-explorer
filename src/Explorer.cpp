#include "../include/Explorer.hpp"
#include "../include/InvalidInputException.hpp"
#include "../include/FibonacciGenerator.hpp"
#include "../include/RecursivelySum.hpp"
#include "../include/MatrixMultiplier.hpp"
#include "../include/CezarCipher.hpp"
#include "../include/PESELGenerator.hpp"
#include "../include/DaysDifference.hpp"
#include "../include/ArrayAddition.hpp"

#include <iostream>
#include <limits>

Explorer::Explorer() {
    // create all tasks objects and run mainMenu
    std::unique_ptr<Task> fibonacciGeneratorIterative = std::make_unique<FibonacciGenerator>("Fibonacci Generator Iterative");
    tasks.push_back(std::move(fibonacciGeneratorIterative));
    std::unique_ptr<Task> fibonacciGeneratorRecursive = std::make_unique<FibonacciGenerator>("Fibonacci Generator Recursive");
    tasks.push_back(std::move(fibonacciGeneratorRecursive));
    std::unique_ptr<Task> recursivelySum = std::make_unique<RecursivelySum>("Recursive Sum from 1 to 100");
    tasks.push_back(std::move(recursivelySum));
    std::unique_ptr<Task> matrixMultiplier = std::make_unique<MatrixMultiplier>("Multiplication of Two Given Matrices");
    tasks.push_back(std::move(matrixMultiplier));
    std::unique_ptr<Task> cezarCipher = std::make_unique<CezarCipher>("Cezar Cipher Program");
    tasks.push_back(std::move(cezarCipher));
    std::unique_ptr<Task> PESEL_Generator = std::make_unique<PESELGenerator>("PESEL Generator");
    tasks.push_back(std::move(PESEL_Generator));
    std::unique_ptr<Task> days_difference = std::make_unique<DaysDifference>("Calculate Days Difference");
    tasks.push_back(std::move(days_difference));
    std::unique_ptr<Task> array_addition = std::make_unique<ArrayAddition>("Sum of Two Numbers From Arrays");
    tasks.push_back(std::move(array_addition));
    mainMenu();  
}

Explorer::~Explorer() {}

void Explorer::mainMenu() const {
    size_t choice = 0;
    do {
        printHeader();
        int count = 1;
        for(const auto& task: tasks) {
            std::cout << "\t" << count << ".\t" << task->getName() << std::endl;
            ++count;
        }
        std::cout << "\t0.\tExit" << std::endl;
        std::cout << "\n\tWhich task do you want to explore? ";
        try {
            std::cin >> choice;
            if (std::cin.fail() || choice>tasks.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            else if (choice)
                taskMenu(choice);
        } catch (const InvalidInputException &ex) {
            consoleAnimator.clear();
            std::cerr << ex.what() << std::endl;
        }
    } while (choice);
}

void Explorer::taskMenu(int choice) const {
    
    consoleAnimator.clear();
    int subchoice = 1;
    do {
        printHeader();
        std::cout << "\t1.\tRun the program\n";
        std::cout << "\t2.\tShow me the code!\n";
        std::cout << "\t0.\tReturn\n";

        std::cout << "\n\tWhat do you want to do? ";
        try {
            std::cin >> subchoice;
            consoleAnimator.clear();
            if (std::cin.fail() || subchoice>2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            else if (subchoice == 1)
                tasks.at(choice-1)->execute();
            else if (subchoice == 2)
                tasks.at(choice-1)->showCode();
        } catch (const InvalidInputException &ex) {
            consoleAnimator.clear();
            std::cerr << ex.what() << std::endl;
        }
    } while (subchoice);
}

void Explorer::printHeader() const {
    std::cout << std::endl;
    std::cout << "\t..........................................\n";
    std::cout << "\t----- C++1 LABORATORY TASKS EXPLORER -----\n";
    std::cout << "\t``````````````````````````````````````````" << std::endl;
}