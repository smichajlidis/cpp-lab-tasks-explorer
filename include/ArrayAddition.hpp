#ifndef _ARRAYADDITION_HPP_
#define _ARRAYADDITION_HPP_

#include "Task.hpp"

class ArrayAddition: public Task {
public:
    virtual void execute() const override;
    virtual void showCode() const override;
    ArrayAddition(const std::string& name);
};

#endif