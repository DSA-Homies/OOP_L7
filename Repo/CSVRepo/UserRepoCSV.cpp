#include "UserRepoCSV.h"

using namespace repo;

/**
 * @brief the constructor of the class UserRepoCsv
 * @param initLIst the vector to store the users
 * @param _filename the filename representing the csv data base where the users and their passwords are saved
 */
UserRepoCSV::UserRepoCSV(const string &_filename) {
    filename = _filename;
    loadFromFile();
};

/**
 * @brief saves the users with their usernames and passwords to the csv file
 */
void UserRepoCSV::saveToFile() {
    ofstream file(filename, ios::out);
    if (file.is_open()) {
        for (const auto &user: userList) {
            file << user.toCSVString() << "\n";
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
};

/**
 * @brief loads all the users with their usernames and their passwords from the csv file
 */
void UserRepoCSV::loadFromFile() {
    userList.clear();
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string username, passwordHash, type;
            if (getline(iss, username, ',') && getline(iss, passwordHash, ',') && getline(iss, type)) {
                userList.emplace_back(username, passwordHash, User::strToStatus(type));
            }
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }

}

/**
 * @return the entire vector containing the users
 */
vector<User> UserRepoCSV::getAll() const {
    return userList;
}

/**
 * @brief function that saves an user to the userList vector and also to the csv file
 * @param user the user to be saved
 */
void UserRepoCSV::add(const User &user) {
    loadFromFile();
    userList.push_back(user);
    saveToFile();
}

/**
 * @brief removes an user from the userList vector and also from the csv file
 * @param user to be removed from the file
 * @return true if the user was successfully removed, false otherwise
 */
bool UserRepoCSV::remove(const User &user) {
    auto it = find(userList.begin(), userList.end(), user);
    if (it != userList.end()) {
        userList.erase(it);
        saveToFile();
        return true;
    }

    return false;
}

/**
 * @brief updates the user located at a given index
 * @throws out_of_range exception if the index is invalid
 * @param index
 * @param newUser
 */
void UserRepoCSV::update(int index, const User &newUser) {
    if (index < 0 || index > userList.size()) {
        throw out_of_range("UserRepoCSV::update(): Index out of range for index " + to_string(index));
    }

    userList[index] = newUser;
    saveToFile();
}

/**
 * @brief Removes the user at a certain index in the list
 * @param index
 * @throws out_of_range exception if the index is invalid
 */
void UserRepoCSV::removeAtIndex(int index) {
    if (index < 0 || index > userList.size())
        throw out_of_range("UserRepoCSV::removeAtIndex(): Index out of range for index " + to_string(index));

    userList.erase(userList.begin() + index);
    saveToFile();
}

/**
 * @returns the index of the user passed by parameter or -1 if the user is not found
 * @param user
 */
int UserRepoCSV::getIndexOf(const User &user) const {
    auto it = find(userList.begin(), userList.end(), user);
    if (it != userList.end()) {
        return (int) distance(userList.begin(), it);
    }
    return -1;
}

User UserRepoCSV::getUserByName(const string &name) const {
    for (const auto &user: userList) {
        if (user.getUsername() == name) {
            return user;
        }
    }

    throw Exception::InvalidUserException("UserRepoCSV::getUserByName(): User not found!");
}

/**
 * @returns the user at the given index
 * @param index
 * @throws out_of_range exception if the index is invalid
 */
User UserRepoCSV::getUserAtIndex(int index) const {
    if (index < 0 || index > userList.size())
        throw out_of_range("UserRepoCSV::getUserAtIndex(): Index out of range for index " + to_string(index));

    return userList[index];
}
