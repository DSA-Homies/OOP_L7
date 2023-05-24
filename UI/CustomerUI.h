#ifndef OOP_L5_CUSTOMERUI_H
#define OOP_L5_CUSTOMERUI_H


#include "UI.h"
#include <algorithm>
#include <utility>


namespace ui {
    class CustomerUI : public UI {

    public:
        explicit CustomerUI(shared_ptr<ctrl::ScooterController> sharedPtr) : UI(std::move(sharedPtr)) {

        }

        /**
         * Entry point of CustomerUI
         */
        void mainMenu() const override {
            vector<string> options = {"Rent Scooter", "Return Scooter", "Reserve Scooter", "Search by Location",
                                      "Filter by commissioning date", "Filter by kilometers", "Back", "Exit"};
            int option = Widgets::menu("Customer Menu", options);

            switch (option) {
                case 1:
                    rentScooter();
                    break;
                case 2:
                    returnScooter();
                    break;
                case 3:
                    reserveScooter();
                    break;
                case 4:
                    searchByLocation();
                    break;
                case 5:
                    filterByCommissioningDate();
                    break;
                case 6:
                    filterByKilometers();
                    return;
                case 7:
                    return;
                case 8:
                    std::exit(0);
                default:
                    mainMenu();
            }

            mainMenu();
        }

    private:
        /**
         * @brief Rent a scooter if available/reserved and no other scooter is currently rented
         */
        void rentScooter() const {
            Scooter myScooter = controller->getMyScooter();
            if (myScooter.getStatus() == domain::IN_USE) {
                cout << "You already have a scooter rented:\n";
                cout << myScooter.toString() << '\n';
                return;
            }

            if (myScooter.getStatus() == domain::RESERVED) {
                cout << "You reserved the following scooter:\n";
                cout << myScooter.toString() << '\n';
                cout << "Do you want to rent it? (y/n) -> ";
                char option;
                cin >> option;
                if (option == 'y') {
                    controller->setStatus(myScooter.getId(), domain::IN_USE);
                    myScooter.setStatus(domain::IN_USE);
                    controller->setMyScooter(myScooter);

                    cout << "Scooter rented successfully: \n";
                    cout << myScooter.toString() << '\n';
                } else {
                    if (option == 'n') {
                        return;
                    } else {
                        cout << "Invalid option\n";
                    }
                }
                return;
            }

            auto matches = controller->getScootersByStatus(domain::PARKED);
            Widgets::tableView(matches);

            string id;
            cout << "Enter the ID of the scooter you want to rent -> ";
            cin >> id;

            auto match = std::find_if(matches.begin(), matches.end(), [&](const auto &scooter) {
                return scooter.getId() == id;
            });

            if (match != matches.end()) {
                controller->setStatus(id, domain::IN_USE);
                controller->setMyScooter(controller->getScooterById(id));
            } else {
                cout << "Invalid Scooter ID" << endl;
            }
        }

        /**
         * @brief Return a scooter if rented
         */
        void returnScooter() const {
            Scooter myScooter = controller->getMyScooter();
            if (myScooter.getStatus() != domain::IN_USE) {
                cout << "You don't have a scooter rented\n";
                return;
            } else {
                cout << "You have the following scooter rented:\n";
                cout << myScooter.toString() << '\n';
                cout << "Do you want to return it? (y/n) -> ";
                char option;
                cin >> option;
                if (option == 'y') {
                    controller->setStatus(myScooter.getId(), domain::PARKED);
                    myScooter.setStatus(domain::PARKED);
                    controller->setMyScooter(myScooter);
                } else {
                    if (option == 'n') {
                        return;
                    } else {
                        cout << "Invalid option\n";
                        return;
                    }
                }
                return;
            }

        }

        /**
         * @brief Reserve a scooter if available and no other scooter is currently rented
         */
        void reserveScooter() const {
            Scooter myScooter = controller->getMyScooter();
            if (myScooter.getStatus() == domain::IN_USE || myScooter.getStatus() == domain::RESERVED) {
                cout << "You already have a scooter rented / reserved\n";
                return;
            }

            auto matches = controller->getScootersByStatus(domain::PARKED);
            Widgets::tableView(matches);

            string id;
            cout << "Enter the ID of the scooter you want to reserve -> ";
            cin >> id;

            auto match = std::find_if(matches.begin(), matches.end(), [&](const auto &scooter) {
                return scooter.getId() == id;
            });

            if (match != matches.end()) {
                controller->setStatus(id, domain::RESERVED);
                controller->setMyScooter(controller->getScooterById(id));
            } else {
                cout << "Invalid Scooter ID" << endl;
            }
        }
    };
}
#endif //OOP_L5_CUSTOMERUI_H
