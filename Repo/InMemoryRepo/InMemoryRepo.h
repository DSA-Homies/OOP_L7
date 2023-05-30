#ifndef OOP_L5_SCOOTERREPO_H
#define OOP_L5_SCOOTERREPO_H

#include <vector>

#include "../../Domain/Scooter.h"
#include "../../Repo/CRUDRepo/CRUDRepo.h"

using namespace std;
using namespace domain;

namespace repo {

    class InMemoryRepo : public CRUDRepo{
    private:

    public:
        explicit InMemoryRepo(const vector<Scooter>& initList = {});

        [[nodiscard]] Scooter getMyScooter() const override;

        void setMyScooter(const Scooter &_myScooter) override;

        void add(const Scooter& scooter) override;

        bool remove(const Scooter &scooter) override;

        void removeAtIndex(int index) override;

        void update(int index, const Scooter &newScooter) override;

        void updateStatus(int index, Status status) override;

        int getIndexOf(const Scooter &scooter) override;

        Scooter getScooterAtIndex(int index) override;

        vector<Scooter> getAll() override;
    };
}

#endif //OOP_L5_SCOOTERREPO_H
