#ifndef _TASK_HPP_
#define _TASK_HPP_

#include <string>

class Task {
    std::string name;
public:
    virtual std::string getName() const;
    virtual void execute() const = 0;
    virtual void showCode() const = 0;
    Task(const std::string& name);
    ~Task();
};

#endif