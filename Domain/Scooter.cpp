#include "Scooter.h"

#include <utility>
#include "../Utils/utils.h"

using namespace domain;

Scooter::Scooter(string id, string model, time_t commissioningDate, float kilometer,
                 string location, Status status) : id(std::move(id)), model(std::move(model)),
                                                   commissioningDate(commissioningDate),
                                                   kilometer(kilometer), location(std::move(location)),
                                                   status(status) {}

Scooter::Scooter(string id, string model, const string &commissioningDate, float kilometer,
                 string location, Status status) : id(std::move(id)), model(std::move(model)),
                                                   commissioningDate(strToTime(commissioningDate)),
                                                   kilometer(kilometer), location(std::move(location)),
                                                   status(status) {}

string Scooter::getId() const {
    return id;
}

void Scooter::setId(const string &_id) {
    this->id = _id;
}

string Scooter::getModel() const {
    return model;
}

void Scooter::setModel(const string &_model) {
    this->model = _model;
}

time_t Scooter::getCommissioningDate() const {
    return commissioningDate;
}

string Scooter::getCommissioningDateStr() const {
    return timeToStr(commissioningDate);
}

void Scooter::setCommissioningDate(time_t _commissioningDate) {
    this->commissioningDate = _commissioningDate;
}

void Scooter::setCommissioningDate(const string &_commissioningDate) {
    this->commissioningDate = strToTime(_commissioningDate);
}

float Scooter::getKilometer() const {
    return kilometer;
}

void Scooter::setKilometer(float _kilometer) {
    this->kilometer = _kilometer;
}

string Scooter::getLocation() const {
    return location;
}

void Scooter::setLocation(const string &_location) {
    this->location = _location;
}

Status Scooter::getStatus() const {
    return status;
}

string Scooter::getStatusStr() const {
    return statusToStr(status);
}

string Scooter::getKilometerStr() const {
    return formatFloat(kilometer, 1);
}

void Scooter::setStatus(Status _status) {
    this->status = _status;
}

bool Scooter::operator==(const Scooter &other) const {
    return id == other.id;
}

bool Scooter::operator!=(const Scooter &other) const {
    return !(*this == other);
}

string Scooter::toString() const {
    return id + ' ' + model + ' ' + timeToStr(commissioningDate) + ' ' + formatFloat(kilometer, 1) + ' ' + location +
           ' ' +
           statusToStr(status);
}

vector<string> Scooter::toList() const {
    vector<string> details = {id, model, timeToStr(commissioningDate), formatFloat(kilometer, 1), location,
                              statusToStr(status)};
    return details;
}
