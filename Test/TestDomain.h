//
// Created by Mircea on 5/16/2023.
//

#ifndef OOP_L5_TESTDOMAIN_H
#define OOP_L5_TESTDOMAIN_H


#include "../Domain/Scooter.h"
#include "../Utils/utils.h"
#include <cassert>

using domain::Scooter;
using domain::Status;

/**
 * This function tests the domain and its functionalities
 */
void testDomain() {

    cout << "Testing Domain" << endl;
    {
        Scooter scooter("aaa", "Bolt", strToTime("16-05-2023"), 10.0, "Blaga", Status::PARKED);
        assert(scooter.getId() == "aaa");
        assert(scooter.getModel() == "Bolt");
        assert(scooter.getCommissioningDate() == strToTime("16-05-2023"));
        assert(scooter.getKilometer() == 10.0);
        assert(scooter.getLocation() == "Blaga");
        assert(scooter.getStatus() == Status::PARKED);
    }


    {
        Scooter scooter("bbb", "Bolt", strToTime("16-05-2023"), 10.0, "Blaga", Status::PARKED);
        assert(scooter.getId() == "bbb");
        assert(scooter.getModel() == "Bolt");
        assert(scooter.getCommissioningDate() == strToTime("16-05-2023"));
        assert(scooter.getKilometer() == 10.0);
        assert(scooter.getLocation() == "Blaga");
        assert(scooter.getStatus() == Status::PARKED);

        scooter.setId("ccc");
        scooter.setModel("Gion");
        scooter.setCommissioningDate("11-01-2020");
        scooter.setKilometer(20.0);
        scooter.setLocation("Ciorilor");
        scooter.setStatus(Status::AWAITING);

        assert(scooter.getId() == "ccc");
        assert(scooter.getModel() == "Gion");
        assert(scooter.getCommissioningDate() == strToTime("11-01-2020"));
        assert(scooter.getKilometer() == 20.0);
        assert(scooter.getLocation() == "Ciorilor");
        assert(scooter.getStatus() == Status::AWAITING);

    }

    cout << "Domain Test finished" << endl;
}
#endif //OOP_L5_TESTDOMAIN_H
