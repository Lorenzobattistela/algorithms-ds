#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class FullStackException : public std::exception {
    public:
        const char* what() const noexcept {
            return "Stack is full.";
        }
};

class EmptyStackException : public std::exception {
    public:
        const char* what() const noexcept {
            return "Stack is empty.";
        }
};

#endif
