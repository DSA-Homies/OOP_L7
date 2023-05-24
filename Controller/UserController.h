#ifndef OOP_L7_USERCONTROLLER_H
#define OOP_L7_USERCONTROLLER_H

#include "../Repo/CSVRepo/UserRepoCSV.h"
#include "../Exception/InvalidUserException.h"


using namespace repo;

namespace ctrl {
    class UserController {
    private:
        unique_ptr<UserRepoCSV> repo;
    public:
        explicit UserController(unique_ptr<UserRepoCSV> _repoPtr);

        void add(const string &username, const string &password);

        void remove(const string &username);

        void update(const User &newUser);

    };
}
#endif //OOP_L7_USERCONTROLLER_H
