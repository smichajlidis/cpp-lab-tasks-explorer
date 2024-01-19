#ifndef _FIBONACCIGENERATOR_HPP_
#define _FIBONACCIGENERATOR_HPP_

#include <string>
#include "Task.hpp"

class FibonacciGenerator: public Task {
public:
    FibonacciGenerator(const std::string& name);
};

#endif