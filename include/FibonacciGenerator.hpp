#ifndef _FIBONACCIGENERATOR_HPP_
#define _FIBONACCIGENERATOR_HPP_

#include <string>
#include "Task.hpp"

class FibonacciGenerator: public Task {
public:
    virtual void execute() const;
    void fibIterative(int) const;
    FibonacciGenerator(const std::string& name);
};

#endif