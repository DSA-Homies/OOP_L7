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
        explicit UserRepoCSV(const vector<User> &initLIst, const string &_filename);

        void add(const User &user);

        bool remove(const User &user);

        void removeAtIndex(int index);

        void update(int index, const User &newUser);

        int getIndexOf(const User &user) const;

        User getUserAtIndex(int index) const;

        vector<User> getAll() const;

    };
}


#endif //OOP_L7_USERREPOCSV_H
