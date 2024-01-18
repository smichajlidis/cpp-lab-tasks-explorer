#include "../include/Explorer.hpp"
#include "../include/InvalidInputException.hpp"
#include <iostream>
#include <limits>

Explorer::Explorer() {
    mainMenu();
}

Explorer::~Explorer() {}

void Explorer::mainMenu() const {
    size_t choice;
    bool invalidInput;
    do {
        invalidInput = false;
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
                invalidInput = true;
                throw InvalidInputException();
            }
        } catch (const InvalidInputException &ex) {
            consoleAnimator.clear();
            std::cerr << ex.what() << std::endl;
        }
    } while (invalidInput);
}