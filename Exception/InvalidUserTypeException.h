#ifndef OOP_L7_INVALIDUSERTYPEEXCEPTION_H
#define OOP_L7_INVALIDUSERTYPEEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

namespace Exception {
    class InvalidUserTypeException : public exception {
    private:
        string message;
    public:
        explicit InvalidUserTypeException(const string &message) {
            this->message = message;
        }

        const char *what() const noexcept override {
            return this->message.c_str();
        }
    };
}

#endif //OOP_L7_INVALIDUSERTYPEEXCEPTION_H
