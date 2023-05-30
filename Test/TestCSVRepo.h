//
// Created by Luca Tudor on 17.05.2023.
//

#ifndef OOP_L6_TESTCSVREPO_H
#define OOP_L6_TESTCSVREPO_H

#include <iostream>
#include <cassert>
#include "../Repo/CSVRepo/ScooterRepoCSV.h"
#include "../Utils/utils.h"

void testCSVRepo() {

    cout << "Testing CSV Repo..." << endl;

    ScooterRepoCSV repoTest(vector<Scooter>{}, "../Repo/DataBase/testDataBase1.csv");

    Scooter scooter1("aaa", "Bolt 4", strToTime("16-05-2023"), 10.0, "Str. Blaga", Status::PARKED);
    Scooter scooter2("bbb", "Bolt 4", strToTime("20-03-2022"), 15.0, "Str. Eminescu", Status::IN_USE);
    Scooter scooter3("ccc", "Bolt 5", strToTime("15-06-2022"), 20.0, "Str. Enescu", Status::AWAITING);
    Scooter scooter4("ddd", "Bolt 5", strToTime("10-07-2023"), 22.2, "Str. Bacovia", Status::DECOMMISSIONED);

    repoTest.add(scooter1);
    repoTest.add(scooter2);
    repoTest.add(scooter3);
    repoTest.add(scooter4);

//    assert(repo.getIndexOf(scooter1) == 0);
//    assert(repo.getAll().front() == scooter1);
//    assert(repo.getAll().back() == scooter4);

//    repo.getAll().front() == scooter1;
    assert(repoTest.getAll().size() == 4);
//    assert(repo.getAll().size() == 4);

    repoTest.remove(scooter3);
    repoTest.remove(scooter2);


    cout << "CSV Repo tested successfully!" << endl;
}

#endif //OOP_L6_TESTCSVREPO_H
