#ifndef OOP_L7_USERREPOCSV_H
#define OOP_L7_USERREPOCSV_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "../../Domain/User.h"


using namespace std;
using namespace domain;

namespace repo {
    class UserRepoCSV {
    private:
        string filename;
        vector<User> userList;

        void saveToFile();

        void loadFromFile();

    public:
        explicit UserRepoCSV(const string &_filename = "../Repo/DataBase/UserDataBase.csv");

        void add(const User &user);

        bool remove(const User &user);

        void removeAtIndex(int index);

        void update(int index, const User &newUser);

        [[nodiscard]] int getIndexOf(const User &user) const;

        [[nodiscard]] User getUserAtIndex(int index) const;

        [[nodiscard]] vector<User> getAll() const;

    };
}


#endif //OOP_L7_USERREPOCSV_H
