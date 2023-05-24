#ifndef OOP_L5_SCOOTEREXCEPTION_H
#define OOP_L5_SCOOTEREXCEPTION_H

#include <string>
#include <vector>
#include <exception>

using namespace std;

/**
 * Custom exception class that inherits from the public class exception and returns the custom error message
 */
namespace Exception {
    class InvalidScooterIdException : public exception{
    private:
        string message;
    public:
        explicit InvalidScooterIdException(const string &message) {
            this->message = message;
        }

        const char *what() const noexcept override {
            return this->message.c_str();
        }
    };
}


#endif //OOP_L5_SCOOTEREXCEPTION_H
