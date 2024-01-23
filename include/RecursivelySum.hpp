#ifndef _RECURSIVELYSUM_HPP_
#define _RECURSIVELYSUM_HPP_

#include "Task.hpp"

class RecursivelySum: public Task {
public:
    virtual void execute() const override;
    virtual void showCode() const override;
    int recFunction(int) const;
    RecursivelySum(const std::string& name);
};

#endif