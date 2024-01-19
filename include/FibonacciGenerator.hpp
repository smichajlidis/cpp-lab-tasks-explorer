#ifndef _FIBONACCIGENERATOR_HPP_
#define _FIBONACCIGENERATOR_HPP_

#include <string>
#include <vector>
#include "Task.hpp"

class FibonacciGenerator: public Task {
public:
    virtual void execute() const;
    void fibIterative(int) const;
    std::vector<int> fibRecursive(int) const;
    FibonacciGenerator(const std::string& name);
};

#endif