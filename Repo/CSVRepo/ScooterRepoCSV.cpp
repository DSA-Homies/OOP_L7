//
// Created by Luca Tudor on 17.05.2023.
//

#include <fstream>
#include <sstream>
#include "ScooterRepoCSV.h"
#include <algorithm>
#include <utility>

using namespace repo;

ScooterRepoCSV::ScooterRepoCSV(const vector<Scooter> &initLIst, string filename) : CRUDRepo(initLIst),
                                                                                   filename(std::move(filename)) {
    loadFromFile();
    if (scooterList.empty()) {
        scooterList = initLIst;
        saveToFile();
    }
}

void ScooterRepoCSV::add(const Scooter &scooter) {
    scooterList.push_back(scooter);
    saveToFile();
}

bool ScooterRepoCSV::remove(const Scooter &scooter) {
    loadFromFile();
    auto it = find(scooterList.begin(), scooterList.end(), scooter);
    if (it != scooterList.end()) {
        scooterList.erase(it);
        saveToFile();
        return true;
    }
    return false;
}

void ScooterRepoCSV::update(int index, const Scooter &newScooter) {
    loadFromFile();
    if (index < 0 || index > scooterList.size()) {
        throw out_of_range("ScooterRepoCSV::update(): Index out of range for index " + to_string(index));
    }

    scooterList[index] = newScooter;
    saveToFile();
}

void ScooterRepoCSV::updateStatus(int index, Status status) {
    loadFromFile();
    if (index < 0 || index > scooterList.size()) {
        throw out_of_range("ScooterRepoCSV::updateStatus(): Index out of range for index " + to_string(index));
    }

    scooterList[index].setStatus(status);
    saveToFile();
}

int ScooterRepoCSV::getIndexOf(const Scooter &scooter) {
    loadFromFile();
    auto it = std::find(scooterList.begin(), scooterList.end(), scooter);
    if (it != scooterList.end()) {
        return (int) std::distance(scooterList.begin(), it);
    }
    return -1;
}

Scooter ScooterRepoCSV::getScooterAtIndex(int index) {
    loadFromFile();
    if (index < 0 || index > scooterList.size()) {
        throw out_of_range("ScooterRepoCSV::getScooterAtIndex(): Index out of range for index " + to_string(index));
    }
    return scooterList[index];
}

vector<Scooter> ScooterRepoCSV::getAll() {
    return scooterList;
}

void ScooterRepoCSV::saveToFile() {
    ofstream file(filename, ios::out);
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

void ScooterRepoCSV::loadFromFile() {
    scooterList.clear();
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string id, model, commissioningDate, kilometer, location, status;
            if (getline(iss, id, ',') && getline(iss, model, ',') &&
                getline(iss, commissioningDate, ',') && getline(iss, kilometer, ',') &&
                getline(iss, location, ',') && getline(iss, status)) {
                scooterList.emplace_back(id, model, strToTime(commissioningDate), stof(kilometer), location,
                                         Status(stoi(status)));
            }
        }
        file.close();
    } else {
        throw runtime_error("Could not open file!");
    }
}

void ScooterRepoCSV::removeAtIndex(int index) {
    loadFromFile();
    if (index < 0 || index > scooterList.size())
        throw out_of_range("ScooterRepoCSV::removeAtIndex(): Index out of range for index " + to_string(index));

    scooterList.erase(scooterList.begin() + index);
    saveToFile();
}

Scooter ScooterRepoCSV::getMyScooter() const {
    return myScooter;
}

void ScooterRepoCSV::setMyScooter(const Scooter &_myScooter) {
    myScooter = _myScooter;
}

void ScooterRepoCSV::setFile(const std::string fileName_) {
    filename = fileName_;
}