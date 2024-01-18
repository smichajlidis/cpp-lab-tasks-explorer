#ifndef _INVALIDINPUTEXCEPTION_HPP_
#define _INVALIDINPUTEXCEPTION_HPP_
#include <stdexcept>

class InvalidInputException: public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Invalid input, try again. You should give only a number of existing task.";
    }
    InvalidInputException() {};
    ~InvalidInputException() {};
};

#endif