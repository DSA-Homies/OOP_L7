//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_CRUDREPO_H
#define OOP_L6_CRUDREPO_H


#include <vector>
#include "../Domain/Scooter.h"


using namespace domain;

class CRUDRepo {
protected:
    vector<Scooter> scooterList;
    Scooter myScooter{};
public:
    explicit CRUDRepo(const vector<Scooter>& initLIst){};
    virtual  Scooter getMyScooter() const = 0;
    virtual void setMyScooter(const Scooter& scooter) = 0;
    virtual void add(const Scooter& scooter) = 0;
    virtual bool remove(const Scooter& scooter) = 0;
    virtual void removeAtIndex(int index) = 0;
    virtual void update(int index, const Scooter& newScooter) = 0;
    virtual void updateStatus(int index, Status status) = 0;
    virtual int getIndexOf(const Scooter& scooter) = 0;
    virtual Scooter getScooterAtIndex(int index) = 0;
    virtual std::vector<Scooter> getAll() = 0;
    virtual ~CRUDRepo() = default;
};


#endif //OOP_L6_CRUDREPO_H
