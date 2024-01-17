#ifndef _TASK_HPP_
#define _TASK_HPP_

#include <string>

class Task {
    std::string name;
public:
    virtual std::string getName() const;
    Task(std::string& name);
    ~Task();
};

#endif