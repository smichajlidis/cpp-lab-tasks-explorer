#ifndef _CEZARCIPHER_HPP_
#define _CEZARCIPHER_HPP_

#include "Task.hpp"

class CezarCipher: public Task {
public:
    virtual void execute() const override;
    virtual void showCode() const override;
    CezarCipher(const std::string& name);
};

#endif