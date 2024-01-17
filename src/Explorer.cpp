#include "../include/Explorer.hpp"
#include <iostream>

Explorer::Explorer() {}

Explorer::~Explorer() {}

void Explorer::mainMenu() const {
    int count = 1;
    for(const auto& task: tasks) {
        std::cout << "\t" << count << ".\t" << task->getName() << std::endl;
        ++count;
    }
    char choice;
    std::cout << "\nWhich task do you want to explore?";
    std::cin >> choice;
}