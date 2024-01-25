#ifndef _PESELGENERATOR_HPP_
#define _PESELGENERATOR_HPP_

#include "Task.hpp"

class PESELGenerator: public Task {
public:
    virtual void execute() const override;
    virtual void showCode() const override;
    PESELGenerator(const std::string& name);
};

#endif