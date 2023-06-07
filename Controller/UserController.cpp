#include "UserController.h"

using namespace ctrl;
using namespace Exception;

/**
 * @brief the constructor for the userController class
 * @param _repoPtr the UserRepoCSV repository
 */
UserController::UserController(unique_ptr<UserRepoCSV> _repoPtr) {
    repo = std::move(_repoPtr);
}

/**
 * @brief adds an user to the csv data base with their username and passwordHash
 * @param username of the user
 * @param password of the user
 */
void UserController::add(const string &username, const string &password, const UserType &type) {
    repo->add(User(username, sha256(password), type));
}

/**
 * @brief removes an user from the csv data base based on the username
 * @param username of the user
 */
void UserController::remove(const string &username) {
    User tempUser(username);

    bool found = false;

    int index = repo->getIndexOf(tempUser);

    if (index != -1) {
        repo->removeAtIndex(index);
        found = true;
    }

    if (!found)
        throw InvalidUserException("UserController::removeUser(): User not found!");
}

/**
 * @brief updates a user based on the username
 * @param newUser
 */
void UserController::update(const User &newUser) {
    User tempUser(newUser.getUsername());

    int index = repo->getIndexOf(tempUser);

    if (index != -1) {
        repo->update(index, newUser);
    } else {
        throw InvalidUserException("UserController::updateUser(): User not found!");
    }

}

bool UserController::validate(const string &username, const string &password) {
    try {
        User tempUser = repo->getUserByName(username);
        return tempUser.getPasswordHash() == sha256(password);
    } catch (InvalidUserException &e) {
        return false;
    }
}
