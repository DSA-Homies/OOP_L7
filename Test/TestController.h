//
// Created by Mircea on 5/16/2023.
//



#ifndef OOP_L5_TESTCONTROLLER_H
#define OOP_L5_TESTCONTROLLER_H

#include "../Domain/Scooter.h"
#include "../Controller/ScooterController.h"
#include "../Utils/utils.h"
#include "../Exception/InvalidScooterIdException.h"

#include <cassert>

using namespace repo;
using namespace domain;
using namespace ctrl;
using namespace Exception;

void testController() {
//    ScooterController controller(make_unique<ScooterRepoCSV>());
//
//    Scooter scooter1("aaa", "Bolt 4", strToTime("16-05-2023"), 10.0, "Str. Blaga", Status::PARKED);
//    Scooter scooter2("bbb", "Bolt 4", strToTime("20-03-2022"), 15.0, "Str. Eminescu", Status::IN_USE);
//    Scooter scooter3("ccc", "Bolt 5", strToTime("15-06-2022"), 20.0, "Str. Enescu", Status::AWAITING);
//    Scooter scooter4("ddd", "Bolt 5", strToTime("10-07-2023"), 22.2, "Str. Bacovia", Status::DECOMMISSIONED);
//
//
//    controller.add(scooter1);
//
//    assert(controller.getScooterById("aaa") == scooter1);
//
//    controller.deleteScooter(scooter1.getId());
//
//    try {
//        controller.getScooterById("aaa");
//        assert(false);
//    } catch (const InvalidScooterIdException& e) {
//        assert(true);
//    }

}

#endif //OOP_L5_TESTCONTROLLER_H
