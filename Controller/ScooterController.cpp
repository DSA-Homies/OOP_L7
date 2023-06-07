#include <algorithm>
#include <fstream>
#include "ScooterController.h"
#include "../Utils/Utils.h"
#include "../Exception/InvalidScooterIdException.h"

using namespace ctrl;

using domain::Scooter;

using Exception::InvalidScooterIdException;

ScooterController::ScooterController(unique_ptr<ScooterRepoCSV> _repoPtr) {
    repo = std::move(_repoPtr);
}

/**
 * @brief This function searches for a scooter in the repository by its location and returns a vector of scooters that have
 * the same location as the location given as parameter to the function
 * @param location - the given location to find the scooters
 * @return result - a scooterList of scooters that have the same location as the given parameter
 */
vector<Scooter> ScooterController::searchByLocation(const string &location) const {
    vector<Scooter> allScooters = repo->getAll();
    vector<Scooter> result;
    auto locationMatches = [&](const Scooter &scooter) {
        return toLower(scooter.getLocation()).find(toLower(location)) != string::npos;
    };

    auto it = find_if(allScooters.begin(), allScooters.end(), locationMatches);

    while (it != allScooters.end()) {
        result.push_back(*it);
        it = find_if(++it, allScooters.end(), locationMatches);
    }

    return result;
}

/**
 * @brief displays all the scooters whose commissioning date is lower or equal to the given date as parameter
 * @param _date the date that is used to filter the scooters in the repo
 * @return a scooterList of scooters whose comissioning date is less or equal to the date given as parameter
 */
vector<Scooter> ScooterController::filterByCommissioningDate(const string &_date) const {
    time_t date = strToTime(_date);

    vector<Scooter> matches;

    for (const Scooter &scooter: repo->getAll())
        if (scooter.getCommissioningDate() <= date)
            matches.push_back(scooter);

    // Sort by commissioning date
    sort(matches.begin(), matches.end(), [](const Scooter &a, const Scooter &b) {
        return a.getCommissioningDate() < b.getCommissioningDate();
    });

    return matches;
}

/**
 * @brief displays all the scooters whose commissioning date is lower or equal to the given kilometer as parameter
 * @param kilometer the kilometers that are used to filter the scooters in the repo
 * @return a scooterList of scooters whose kilometers are less or equal to the kilometers given as parameter
 */
vector<Scooter> ScooterController::filterByKilometer(float kilometer) const {
    if (kilometer < 0) {
        throw InvalidScooterIdException("filterByKilometer: Kilometers cannot be negative!");
    }
    vector<Scooter> matches;

    for (const Scooter &scooter: repo->getAll())
        if (scooter.getKilometer() <= kilometer)
            matches.push_back(scooter);

    // Sort by kilometers
    sort(matches.begin(), matches.end(), [](const Scooter &a, const Scooter &b) {
        return a.getKilometer() < b.getKilometer();
    });

    return matches;
}

/**
 * @brief Adds a scooter to the repo
 * @param id the id of the scooter
 * @param model the model name of the scooter
 * @param commissioningDate the commissioning date of the scooter
 * @param kilometer the kilometers of the scooter
 * @param location the location of the scooter
 * @param status the status of the scooter
 */
void ScooterController::add(const string &id, const string &model, time_t commissioningDate, float kilometer,
                            const string &location,
                            Status status) {
    repo->add(Scooter(id, model, commissioningDate, kilometer, location, status));
}

/**
 * @brief Removes a scooter from the repo. It searched the index of the scooter and if it is found then we removeAtIndex
 * the scooter from the repo
 * @param id we search for the desired scooter by its id
 * @throw ScooterException if the scooter was not found in the repo
 */
void ScooterController::deleteScooter(const string &id) {

    Scooter tempScooter(id);
    bool found = false;

    int index = repo->getIndexOf(tempScooter);

    if (index != -1) {
        repo->removeAtIndex(index);
        found = true;
    }

    if (!found) {
        throw InvalidScooterIdException("deleteScooter: Scooter not found");
    }


}

/**
 * @brief sorts the scooters by their commissioning date (scooterA < scooterB)
 * @return a scooterList of vectors that are sorted by their commissioning date
 */
vector<Scooter> ScooterController::sortByCommissioningDate() const {
    vector<Scooter> list = repo->getAll();

    // Sort by commissioning date:
    sort(list.begin(), list.end(), [](const Scooter &a, const Scooter &b) {
        return a.getCommissioningDate() < b.getCommissioningDate();
    });

    return list;
}

/**
 * @brief Get all parked(available) scooters
 * @return a scooterList of the scooters that are parked
 */
vector<Scooter> ScooterController::getScootersByStatus(Status status) const {
    vector<Scooter> list = repo->getAll();

    // Filter by status:
    list.erase(remove_if(list.begin(), list.end(), [&](const Scooter &scooter) {
        return scooter.getStatus() != status;
    }), list.end());

    return list;
}

/**
 * @brief adds a scooter to the repo
 * @param scooter the scooter object to be added to the repo
 */
void ScooterController::add(const Scooter &scooter) {
    repo->add(scooter);
}

/**
 * @brief this function sets or updates the status of a scooter. The scooter is found by its id given as a parameter
 * @param id
 * @param status
 */
void ScooterController::setStatus(const string &id, Status status) {
    Scooter tempScooter(id);
    bool found = false;

    int index = repo->getIndexOf(tempScooter);

    if (index != -1) {
        repo->updateStatus(index, status);
        found = true;
    }

    if (!found) {
        throw InvalidScooterIdException("setStatus: Scooter not found!");
    }
}

/**
 * @brief getter for the current scooter used by the user
 * @return
 */
Scooter ScooterController::getMyScooter() {
    return repo->getMyScooter();
}

/**
 * @brief setter for the current scooter used by the user
 * @param scooter
 */
void ScooterController::setMyScooter(const Scooter &scooter) {
    repo->setMyScooter(scooter);
}

/**
 * @brief gets the scooter by id
 * @param id that is used to find the desired scooter
 * @return a scooter object who we found by its id
 */
Scooter ScooterController::getScooterById(const string &id) {
    vector<Scooter> scooters = repo->getAll();
    auto it = std::find_if(scooters.begin(), scooters.end(), [&](const Scooter &scooter) {
        return scooter.getId() == id;
    });

    if (it != scooters.end()) {
        return *it;
    }

    throw InvalidScooterIdException("getScooterById: Scooter not found!");

}

/**
 * @brief updates the scooter with the given id with the new scooter given as a parameter
 * @param id
 * @param newScooter
 */
void ScooterController::update(const string &id, const Scooter &newScooter) {
    Scooter tempScooter(id);

    int index = repo->getIndexOf(tempScooter);

    if (index == -1)
        throw InvalidScooterIdException("update: Scooter not found!");

    repo->update(index, newScooter);
}

vector<Scooter> ScooterController::getAll() {
    return repo->getAll();
}

void ScooterController::loadFromCSV(const string &filePath) {
    repo->setFile(filePath);
    repo->loadFromFile();
}
