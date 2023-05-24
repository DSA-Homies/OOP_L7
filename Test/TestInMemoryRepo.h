//
// Created by Mircea on 5/16/2023.
//

#ifndef OOP_L5_TESTREPO_H
#define OOP_L5_TESTREPO_H

#include "../Domain/Scooter.h"
#include "../Repo/InMemoryRepo/InMemoryRepo.h"
#include "../Utils/utils.h"

#include <cassert>

/**
 * @brief tests the Repository class and all of its functionalities
 */
void testRepo() {

    cout << "Testing the repository" << endl;
    repo::InMemoryRepo scooterRepo;

    Scooter scooter1("aaa", "Bolt 4", strToTime("16-05-2023"), 10.0, "Str. Blaga", Status::PARKED);
    Scooter scooter2("bbb", "Bolt 4", strToTime("20-03-2022"), 15.0, "Str. Eminescu", Status::IN_USE);
    Scooter scooter3("ccc", "Bolt 5", strToTime("15-06-2022"), 20.0, "Str. Enescu", Status::AWAITING);
    Scooter scooter4("ddd", "Bolt 5", strToTime("10-07-2023"), 22.2, "Str. Bacovia", Status::DECOMMISSIONED);

    Scooter expectedScooter1("aaa", "Bolt 4", strToTime("16-05-2023"), 10.0, "Str. Blaga", Status::PARKED);
    Scooter expectedScooter2("bbb", "Bolt 4", strToTime("20-03-2022"), 15.0, "Str. Eminescu", Status::IN_USE);
    Scooter expectedScooter3("ccc", "Bolt 5", strToTime("15-06-2022"), 20.0, "Str. Enescu", Status::AWAITING);
    Scooter expectedScooter4("ddd", "Bolt 5", strToTime("10-07-2023"), 22.2, "Str. Bacovia", Status::DECOMMISSIONED);


    scooterRepo.add(scooter1);
    scooterRepo.add(scooter2);
    scooterRepo.add(scooter3);
    scooterRepo.add(scooter4);

    assert(scooterRepo.getScooterAtIndex(0) == expectedScooter1);
    assert(scooterRepo.getScooterAtIndex(1) == expectedScooter2);
    assert(scooterRepo.getScooterAtIndex(2) == expectedScooter3);
    assert(scooterRepo.getScooterAtIndex(3) == expectedScooter4);

    scooterRepo.remove(scooter3);

    vector<Scooter> scoovec {scooter1, scooter2, scooter4};

    assert(scooterRepo.getAll() == scoovec);

    scooterRepo.updateStatus(0, IN_USE);

    Scooter statusScooter1("aaa", "Bolt 4", strToTime("16-05-2023"), 10.0, "Str. Blaga", Status::IN_USE);


    assert(scooterRepo.getScooterAtIndex(0) == statusScooter1);

    cout << "Ending Repository Test" << endl;

}

#endif //OOP_L5_TESTREPO_H
