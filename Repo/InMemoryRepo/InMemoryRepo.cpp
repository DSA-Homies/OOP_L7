#include <stdexcept>
#include <algorithm>
#include <utility>
#include "InMemoryRepo.h"

using namespace repo;

InMemoryRepo::InMemoryRepo(const vector<Scooter> &initList) : CRUDRepo(initList) {
    scooterList = initList;
}

/**
 * @return A vector containing all the scooters in the repo
 */
vector<Scooter> InMemoryRepo::getAll() {
    return scooterList;
}

/**
 * Adds a scooter to the repo
 * @param scooter The scooter to be added
 */
void InMemoryRepo::add(const Scooter &scooter) {
    scooterList.push_back(scooter);
}

/**
 * Removes a scooter from the repo
 * @param scooter The scooter to be removed
 * @return True if the scooter was removed, false otherwise
 */
bool InMemoryRepo::remove(const Scooter &scooter) {
    auto it = find(scooterList.begin(), scooterList.end(), scooter);
    if (it != scooterList.end()) {
        scooterList.erase(it);
        return true;
    }

    return false;
}

/**
 * Removes a scooter object at a certain index
 * @param index The index of the scooter to be removed
 * @throws out_of_range if index is invalid
 */
void InMemoryRepo::removeAtIndex(int index) {
    if (index < 0 || index > scooterList.size())
        throw out_of_range("InMemoryRepo::removeAtIndex(): Index out of range for index " + to_string(index));

    scooterList.erase(scooterList.begin() + index);
}

/**
 * Updates a scooter object at a certain index
 * @param index The index of the scooter to be updated
 * @param newScooter The new scooter object to replace the old one
 * @throws out_of_range if index is invalid
 */
void InMemoryRepo::update(int index, const Scooter &newScooter) {
    if (index < 0 || index > scooterList.size())
        throw out_of_range("InMemoryRepo::update(): Index out of range for index " + to_string(index));

    scooterList[index] = newScooter;
}

/**
 * Updates the status of a scooter object at a certain index
 * @param index
 * @param status
 */
void InMemoryRepo::updateStatus(int index, Status status) {
    if (index < 0 || index > scooterList.size())
        throw out_of_range("InMemoryRepo::updateStatus(): Index out of range for index " + to_string(index));

    scooterList[index].setStatus(status);
}

/**
 * @return The index of the scooter if found, -1 otherwise
 * @param scooter The scooter to be searched for
 */
int InMemoryRepo::getIndexOf(const Scooter &scooter) {
    auto it = std::find(scooterList.begin(), scooterList.end(), scooter);
    if (it != scooterList.end())
        return int(distance(scooterList.begin(), it));

    return -1;
}

/**
 * @return The scooter object at a certain index
 * @param index The index of the scooter to be returned
 * @throws out_of_range if index is invalid
 */
Scooter InMemoryRepo::getScooterAtIndex(int index) {
    if (index < 0 || index > scooterList.size())
        throw out_of_range("InMemoryRepo::getScooterAtIndex(): Index out of range for index " + to_string(index));

    return scooterList[index];
}

/**
 * @brief getter for the current scooter that is being used by the user at the moment
 * @return the scooter object that is being used by the user
 */
Scooter InMemoryRepo::getMyScooter() const {
    return myScooter;
}

/**
 * @brief setter for the current scooter that is being used by the user at the moment
 * @param _myScooter the current scooter that we want to set
 */
void InMemoryRepo::setMyScooter(const Scooter &_myScooter) {
    myScooter = _myScooter;
}

