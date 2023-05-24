#include <iostream>
#include "UI/ScooterUI.h"
#include "Controller/ScooterController.h"

#include "../Test/TestAll.h"

using namespace std;
using namespace ui;
using namespace repo;
using namespace ctrl;

int main() {
    cout << sha256("admin") << endl;

    testAll();

    vector<Scooter> initList{
            Scooter("aaa", "Bolt 4", strToTime("16-05-2023"), 10.0, "Str. Blaga", Status::PARKED),
            Scooter("bbb", "Bolt 4", strToTime("20-03-2022"), 15.0, "Str. Eminescu", Status::IN_USE),
            Scooter("ccc", "Bolt 5", strToTime("15-06-2022"), 20.0, "Str. Enescu", Status::AWAITING),
            Scooter("ddd", "Bolt 5", strToTime("10-07-2023"), 22.2, "Str. Bacovia", Status::DECOMMISSIONED),
            Scooter("eee", "Bolt 5", strToTime("06-03-2023"), 30.7, "Str. Caragiale", Status::RESERVED),
            Scooter("fff", "Bolt 5", strToTime("07-01-2022"), 100.20, "Str. Rebreanu", Status::PARKED),
            Scooter("ggg", "Bolt 3", strToTime("12-02-2020"), 76.5, "Str. Racovita", Status::IN_USE),
            Scooter("hhh", "Bolt 3", strToTime("03-10-2020"), 14.0, "Str. Ipsilanti", Status::PARKED),
            Scooter("iii", "Bolt 3", strToTime("19-12-2020"), 35.3, "Str. Arghezi", Status::AWAITING),
            Scooter("jjj", "Bolt 3", strToTime("28-11-2020"), 44.8, "Str. Eliade", Status::DECOMMISSIONED),
    };

    vector<string> options = {"In Memory Repo", "CSV Repo", "Exit"};
    int option = Widgets::menu("Choose Repository", options);
    unique_ptr<CRUDRepo> repoPtr;

        switch (option) {
            case 1:
                repoPtr = make_unique<InMemoryRepo>(initList);
                break;
            case 2:
                repoPtr = make_unique<ScooterRepoCSV>(initList);
                break;
            case 3:
                exit(0);
            default:
                break;
        }

    unique_ptr<ScooterController> controllerPtr = make_unique<ScooterController>(std::move(repoPtr));
    ScooterUI ui(std::move(controllerPtr));
    ui.mainMenu();

}