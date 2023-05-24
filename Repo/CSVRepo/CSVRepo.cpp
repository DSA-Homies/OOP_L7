//
// Created by Luca Tudor on 17.05.2023.
//

#include <fstream>
#include <sstream>
#include "CSVRepo.h"
#include <algorithm>
#include <utility>

using namespace repo;

CSVRepo::CSVRepo(const vector<Scooter> &initLIst, string filename) : CRUDRepo(initLIst),
                                                                     filename_(std::move(filename)) {
    loadFromFile();
    if (scooterList.empty()) {
        scooterList = initLIst;
        saveToFile();
    }
}

void CSVRepo::add(const Scooter &scooter) {
    scooterList.push_back(scooter);
    saveToFile();
}

bool CSVRepo::remove(const Scooter &scooter) {
    loadFromFile();
    auto it = find(scooterList.begin(), scooterList.end(), scooter);
    if (it != scooterList.end()) {
        scooterList.erase(it);
        saveToFile();
        return true;
    }
    return false;
}

void CSVRepo::update(int index, const Scooter &newScooter) {
    loadFromFile();
    if (index < 0 || index > scooterList.size()) {
        throw out_of_range("CSVRepo::update(): Index out of range for index " + to_string(index));
    }

    scooterList[index] = newScooter;
    saveToFile();
}

void CSVRepo::updateStatus(int index, Status status) {
    loadFromFile();
    if (index < 0 || index > scooterList.size()) {
        throw out_of_range("CSVRepo::updateStatus(): Index out of range for index " + to_string(index));
    }

    scooterList[index].setStatus(status);
    saveToFile();
}

int CSVRepo::getIndexOf(const Scooter &scooter) {
    loadFromFile();
    auto it = std::find(scooterList.begin(), scooterList.end(), scooter);
    if (it != scooterList.end()) {
        return (int) std::distance(scooterList.begin(), it);
    }
    return -1;
}

Scooter CSVRepo::getScooterAtIndex(int index) {
    loadFromFile();
    if (index < 0 || index > scooterList.size()) {
        throw out_of_range("CSVRepo::getScooterAtIndex(): Index out of range for index " + to_string(index));
    }
    return scooterList[index];
}

vector<Scooter> CSVRepo::getAll() {
    return scooterList;
}

void CSVRepo::saveToFile() {
    ofstream file(filename_, ios::out);
    if (file.is_open()) {
        for (const auto &scooter: scooterList) {
            file << scooter.getId() << "," << scooter.getModel() << "," << timeToStr(scooter.getCommissioningDate())
                 << ","
                 << scooter.getKilometer() << "," << scooter.getLocation() << "," << scooter.getStatus() << "\n";
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
}

void CSVRepo::loadFromFile() {
    ifstream file(filename_);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string id, model, commissioningDate, kilometer, location, status;
            if (getline(iss, id, ',') && getline(iss, model, ',') &&
                getline(iss, commissioningDate) && getline(iss, kilometer) &&
                getline(iss, location) && getline(iss, status)) {
                scooterList.emplace_back(id, model, strToTime(commissioningDate), stof(kilometer), location,
                                         Status(stoi(status)));
            }
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
}

void CSVRepo::removeAtIndex(int index) {
    loadFromFile();
    if (index < 0 || index > scooterList.size())
        throw out_of_range("CSVRepo::removeAtIndex(): Index out of range for index " + to_string(index));

    scooterList.erase(scooterList.begin() + index);
    saveToFile();
}

Scooter CSVRepo::getMyScooter() const {
    return myScooter;
}

void CSVRepo::setMyScooter(const Scooter &_myScooter) {
    myScooter = _myScooter;
}
