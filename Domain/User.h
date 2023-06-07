#ifndef OOP_L7_USER_H
#define OOP_L7_USER_H

#include <string>
#include <utility>
#include <vector>
#include "../Exception/InvalidUserTypeException.h"
#include "../Utils/utils.h"

using namespace std;

namespace domain {
    enum UserType {
        ADMIN = 0,
        USER = 1
    };

    static vector<string> typeList = {
            "ADMIN",
            "USER"
    };

    class User {
    public:
        [[nodiscard]] static string statusToStr(UserType _status) { return typeList[_status]; }

        [[nodiscard]] static UserType strToStatus(const string &_status) {
            for (int i = 0; i < typeList.size(); ++i)
                if (typeList[i] == _status)
                    return UserType(i);

            throw Exception::InvalidUserTypeException("User::User(): Invalid user type: " + _status);
        }

    private:
        string username;
        string passwordHash;
        UserType type;
        string scooterId;

    public:
        explicit User(string _username = "", string _passwordHash = "", UserType _type = UserType::USER,
                      string _scooterId = "")
                : username(std::move(_username)), passwordHash(std::move(_passwordHash)), type(_type),
                  scooterId(std::move(_scooterId)) {}

        [[nodiscard]] string getUsername() const { return username; }

        [[nodiscard]] string getPasswordHash() const { return passwordHash; }

        [[nodiscard]] string getType() const { return typeList[type]; }

        [[nodiscard]] UserType getTypeEnum() const { return type; }

        [[nodiscard]] string getScooterId() const { return scooterId; }

        void setScooterId(const string &_scooterId) { scooterId = _scooterId; }

        [[nodiscard]]
        vector<string> toList() const {
            return {username, passwordHash, typeList[type], scooterId};
        }

        [[nodiscard]]
        string toCSVString() const {
            return username + "," + passwordHash + "," + typeList[type] + "," + scooterId;
        }

        bool operator==(const User &other) const {
            return username == other.username;
        }

        bool operator!=(const User &other) const {
            return username != other.username;
        }
    };

};


#endif //OOP_L7_USER_H
