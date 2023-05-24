#ifndef OOP_L5_MANAGERUI_H
#define OOP_L5_MANAGERUI_H

#include "UI.h"
#include "../Utils/utils.h"
#include "../Exception/InvalidScooterIdException.h"

#include <utility>

using namespace Exception;

namespace ui {
    class ManagerUI : public UI {

    public:
        explicit ManagerUI(shared_ptr<ctrl::ScooterController> sharedPtr) : UI(std::move(sharedPtr)) {

        }

        /**
         * Entry point of ManagerUI
         */
        void mainMenu() const override {
            vector<string> options = {"Add Scooter", "Remove Scooter", "Set Status", "Search by Location",
                                      "Filter by commissioning date", "Filter by kilometer",
                                      "Sort by commissioning date", "Update Scooter", "Back", "Exit"};
            int option = Widgets::menu("Manager Menu", options);

            switch (option) {
                case 1:
                    addScooter();
                    break;
                case 2:
                    removeScooter();
                    break;
                case 3:
                    setStatus();
                    break;
                case 4:
                    searchByLocation();
                    break;
                case 5:
                    filterByCommissioningDate();
                    break;
                case 6:
                    filterByKilometers();
                    break;
                case 7:
                    sortByCommissioningDate();
                    break;
                case 8:
                    updateScooter();
                    break;
                case 9:
                    cout << "Back\n";
                    return;
                case 10:
                    cout << "App quitting\n";
                    std::exit(0);
                default:
                    mainMenu();
            }

            mainMenu();
        }

    private:
        /**
         * @brief Add a scooter to the scooterList
         */
        void addScooter() const {
            Widgets::printTitle("Add Scooter");
            string id, location, model, status, date;
            float kilometers;

            cout << "id -> ";
            cin >> id;

            try {
                controller->getScooterById(id);

                cout << "Error: id already exists. " << endl;
                addScooter();
            } catch (InvalidScooterIdException &e) {}

            if (id.size() != 3) {
                cout << "Error : id must be 3 characters long. " << endl;
                addScooter();
            }

            cout << "model -> ";
            cin.ignore();
            getline(cin, model);

            if (model.empty()) {
                cout << "Error : model cannot be empty. " << endl;
                addScooter();
            }

            cout << "date -> ";
            cin >> date;

            if (!isDateFormatValid(date)) {
                cout << "Error : date must be in the format dd-mm-yyyy. " << endl;
                addScooter();
            }

            cout << "kilometers -> ";
            cin >> kilometers;

            if (kilometers < 0) {
                cout << "Error : kilometers must be a positive number. " << endl;
                addScooter();
            }

            cout << "location -> ";
            cin.ignore();
            getline(cin, location);

            if (location.empty()) {
                cout << "Error : location cannot be empty. " << endl;
                addScooter();
            }

            cout << "status -> ";
            cin >> status;

            if (!Scooter::isStatusValid(status)) {
                cout
                        << "Error : status must be one of the following : PARKED, RESERVED, IN_USE, AWAITING, DECOMMISSIONED. "
                        << endl;
                addScooter();
            }

            this->controller->add(id, model, strToTime(date), kilometers, location, Scooter::strToStatus(status));
        }

        /**
         * Updates an existing scooter in the repo, changing everything but the id, because the id is unique and cannot
         * be changed
         */
        void updateScooter() const {
            Widgets::printTitle("Update a Scooter");
            string id, location, model, status, date;
            float kilometers;

            cout << "id -> ";
            cin.ignore();
            std::getline(cin, id);

            Scooter oldScooter;
            try {
                oldScooter = controller->getScooterById(id);

            } catch (InvalidScooterIdException &e) {
                cout << "Error: " << e.what() << endl;;
                updateScooter();
            }

            cout << "scooter " << id << ":\n" << oldScooter.toString() << endl;

            cout << "new Model -> ";
            getline(cin, model);

            if (model.empty()) {
                cout << "Error : model cannot be empty. " << endl;
                updateScooter();
            }

            cout << "new Date -> ";
            cin >> date;

            if (!isDateFormatValid(date)) {
                cout << "Error : date must be in the format dd-mm-yyyy. " << endl;
                updateScooter();
            }

            cout << "new kilometers -> ";
            cin >> kilometers;

            if (kilometers < 0) {
                cout << "Error : kilometers must be a positive number. " << endl;
                updateScooter();
            }

            cout << "new Location -> ";
            cin.ignore();
            getline(cin, location);

            if (location.empty()) {
                cout << "Error : location cannot be empty. " << endl;
                updateScooter();
            }

            cout << "new Status -> ";
            cin >> status;

            if (!Scooter::isStatusValid(status)) {
                cout
                        << "Error : status must be one of the following : PARKED, RESERVED, IN_USE, AWAITING, DECOMMISSIONED. "
                        << endl;
                updateScooter();
            }

            this->controller->update(id, Scooter(id, model, strToTime(date), kilometers, location,
                                                 Scooter::strToStatus(status)));
        }

        /**
         * @brief Remove a scooter from the scooterList
         */
        void removeScooter() const {
            Widgets::printTitle("Remove Scooter");
            string id;

            cout << "id -> ";
            cin.ignore();
            std::getline(cin, id);

            try {
                controller->deleteScooter(id);
                std::cout << "Scooter removed successfully. " << std::endl;
            } catch (InvalidScooterIdException &e) {
                cout << "Error : " << e.what() << std::endl;
            }
        }

        /**
         * @brief Set the status of a scooter
         */
        void setStatus() const {
            Widgets::printTitle("Set State");
            string id, status;

            cout << "id -> ";
            cin.ignore();
            std::getline(cin, id);

            cout << "status -> ";
            cin >> status;

            try {
                controller->setStatus(id, Scooter::strToStatus(status));
                std::cout << "Scooter state updated successfully. " << std::endl;
            } catch (InvalidScooterIdException &e) {
                cout << "Error : " << e.what() << std::endl;
            }
        }

        /**
         * @brief Display scooters sorted by commissioning date
         */
        void sortByCommissioningDate() const {
            Widgets::printTitle("Scooters sorted by commissioning date");
            vector<Scooter> list = controller->sortByCommissioningDate();
            Widgets::tableView(list);
        }
    };
}
#endif //OOP_L5_MANAGERUI_H
