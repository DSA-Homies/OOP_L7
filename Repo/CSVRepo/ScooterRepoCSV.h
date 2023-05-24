//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_CSVREPO_H
#define OOP_L6_CSVREPO_H

#include "../CRUDRepo/CRUDRepo.h"
#include "../Utils/Utils.h"

namespace repo {
    class ScooterRepoCSV : public CRUDRepo {
    private:
        string filename;

        void saveToFile();

        void loadFromFile();

    public:
        explicit ScooterRepoCSV(const vector<Scooter> &initLIst, string filename = "../Repo/DataBase/ScooterDataBase.csv");

        void add(const Scooter &scooter) override;

        bool remove(const Scooter &scooter) override;

        void removeAtIndex(int index) override;

        void update(int index, const Scooter &newScooter) override;

        void updateStatus(int index, Status status) override;

        int getIndexOf(const Scooter &scooter) override;

        Scooter getScooterAtIndex(int index) override;

        vector<Scooter> getAll() override;

        Scooter getMyScooter() const override;

        void setMyScooter(const Scooter& _myScooter) override;

    };
}

#endif //OOP_L6_CSVREPO_H
