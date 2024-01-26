#ifndef _DAYSDIFFERENCE_HPP_
#define _DAYSDIFFERENCE_HPP_

#include "Task.hpp"

class DaysDifference: public Task {
public:
    virtual void execute() const override;
    virtual void showCode() const override;
    DaysDifference(const std::string& name);
};

#endif