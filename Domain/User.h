#ifndef OOP_L7_USER_H
#define OOP_L7_USER_H

#include <string>
#include <vector>

using namespace std;

namespace domain {
    enum class UserType {
        ADMIN = 0,
        USER = 1
    };

    static vector<string> typeList = {
            "ADMIN",
            "USER"
    };

    class User {
    private:
        string username, password;

    public:
        [[nodiscard]] static string statusToStr(UserType _status) { return typeList[_status]; }

        [[nodiscard]] static UserType strToStatus(const string &_status) {
            for (int i = 0; i < typeList.size(); ++i)
                if (typeList[i] == _status)
                    return UserType(i);

            return DECOMMISSIONED;
        }

    };
}

#endif //OOP_L7_USER_H
