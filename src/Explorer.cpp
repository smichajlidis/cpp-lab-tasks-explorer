#include "../include/Explorer.hpp"
#include <iostream>

Explorer::Explorer() {
    mainMenu();
}

Explorer::~Explorer() {}

void Explorer::mainMenu() const {
    std::cout << "\n\tC++1 LABORATORY TASKS EXPLORER\n" << std::endl;
    int count = 1;
    for(const auto& task: tasks) {
        std::cout << "\t" << count << ".\t" << task->getName() << std::endl;
        ++count;
    }
    std::cout << "\t0.\tExit" << std::endl;
    int choice; 
    std::cout << "\n\tWhich task do you want to explore? ";
    std::cin >> choice;
}