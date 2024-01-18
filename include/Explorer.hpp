#ifndef _EXPLORER_HPP_
#define _EXPLORER_HPP_

#include "Task.hpp"
#include "ConsoleAnimator.hpp"
#include <memory>
#include <vector>

class Explorer {
    std::vector<std::unique_ptr<Task>> tasks;
    ConsoleAnimator consoleAnimator;
public:
    void mainMenu() const;
    Explorer();
    ~Explorer();
};

#endif