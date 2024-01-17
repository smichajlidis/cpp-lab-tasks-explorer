#include "../include/Task.hpp"

Task::Task(std::string& name)
    : name(name) {}

Task::~Task() {}

std::string Task::getName() const {
    return name;
}