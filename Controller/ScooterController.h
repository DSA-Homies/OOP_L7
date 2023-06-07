#ifndef OOP_L5_SCOOTERCONTROLLER_H
#define OOP_L5_SCOOTERCONTROLLER_H

#include <memory>
#include "../Repo/CSVRepo/ScooterRepoCSV.h"

using namespace repo;

namespace ctrl {
    class ScooterController {
    private:
        unique_ptr<ScooterRepoCSV> repo;
    public:
        explicit ScooterController(unique_ptr<ScooterRepoCSV> _repoPtr);

        [[nodiscard]] vector<Scooter> searchByLocation(const string &location) const;

        [[nodiscard]] vector<Scooter> filterByCommissioningDate(const string &date) const;

        [[nodiscard]] vector<Scooter> sortByCommissioningDate() const;

        [[nodiscard]] vector<Scooter> getScootersByStatus(Status status) const;

        [[nodiscard]] vector<Scooter> filterByKilometer(float kilometer) const;

        void add(const string &id, const string &model, time_t commissioningDate, float kilometer,
                 const string &location,
                 Status status);

        void update(const string &id, const Scooter &newScooter);

        void add(const Scooter &scooter);

        void deleteScooter(const string &id);

        void setStatus(const string &id, Status status);

        Scooter getMyScooter();

        void setMyScooter(const Scooter &scooter);

        Scooter getScooterById(const string &id);

        vector<Scooter> getAll();

        void loadFromCSV(const string &filePath);
    };
}


#endif //OOP_L5_SCOOTERCONTROLLER_H
