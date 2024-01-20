#include "../include/Explorer.hpp"
#include "../include/InvalidInputException.hpp"
#include "../include/FibonacciGenerator.hpp"
#include <iostream>
#include <limits>

Explorer::Explorer() {
    // create all tasks objects and run mainMenu
    std::unique_ptr<Task> fibonacciGeneratorIterative = std::make_unique<FibonacciGenerator>("Fibonacci Generator Iterative");
    tasks.push_back(std::move(fibonacciGeneratorIterative));
    std::unique_ptr<Task> fibonacciGeneratorRecursive = std::make_unique<FibonacciGenerator>("Fibonacci Generator Recursive");
    tasks.push_back(std::move(fibonacciGeneratorRecursive));
    mainMenu();  
}

Explorer::~Explorer() {}

void Explorer::mainMenu() const {
    size_t choice = 0;
    do {
        std::cout << "\n\tC++1 LABORATORY TASKS EXPLORER\n" << std::endl;

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
        std::cout << "\n\t1.\tRun the program\n";
        std::cout << "\t2.\tShow me the code!\n";
        std::cout << "\t0.\tReturn\n";

        std::cout << "\t\nWhat do you want to do? ";
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