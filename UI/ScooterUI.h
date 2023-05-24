#ifndef OOP_L5_SCOOTERUI_H
#define OOP_L5_SCOOTERUI_H

#include "ManagerUI.h"
#include "CustomerUI.h"
#include "../Controller/ScooterController.h"
#include "../Repo/InMemoryRepo/InMemoryRepo.h"
#include "../Repo/CSVRepo//CSVRepo.h"
#include "../Domain/Scooter.h"

using namespace domain;
using namespace repo;

namespace ui {

    class ScooterUI {
        friend class Widgets;

    private:
        shared_ptr<ctrl::ScooterController> ctrl;
        CustomerUI customerUI;
        ManagerUI managerUI;

    public:
        explicit ScooterUI(const std::shared_ptr<ctrl::ScooterController> &_controller)
                : ctrl(_controller), customerUI(_controller), managerUI(_controller) {}

        void mainMenu() const {
            Widgets::printTitle("Bolt Scooters");
            vector<string> options = {"Manager", "Customer", "Exit"};

            int option = Widgets::menu("Main Menu", options);

            switch (option) {
                case 1:
                    managerUI.mainMenu();
                    break;
                case 2:
                    customerUI.mainMenu();
                    break;
                case 3:
                    cout << "App quitting..\n";
                    exit(0);
                default:
                    mainMenu();
            }

            mainMenu();
        }
    };
}
#endif //OOP_L5_SCOOTERUI_H
