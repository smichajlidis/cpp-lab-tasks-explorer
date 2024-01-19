#include "../include/Task.hpp"

Task::Task(const std::string& name)
    : name(name) {}

Task::~Task() {}

std::string Task::getName() const {
    return name;
}