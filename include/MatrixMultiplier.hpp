#ifndef _MATRIXMULTIPLIER_HPP_
#define _MATRIXMULTIPLIER_HPP_

#include "Task.hpp"
#include "ConsoleAnimator.hpp"
#include <vector>

class MatrixMultiplier: public Task {
private:
    ConsoleAnimator consoleAnimator;
public:
    virtual void execute() const override;
    virtual void showCode() const override;
    std::vector<std::vector<int>> loadMatrix() const;
    void matrixMultiplier(const std::vector<std::vector<int>>& m1, const std::vector<std::vector<int>>& m2) const;
    MatrixMultiplier(const std::string& name);
};

#endif