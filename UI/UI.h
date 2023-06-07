#ifndef OOP_L5_UI_H
#define OOP_L5_UI_H

#include <utility>

#include "Widgets.h"
#include "../Controller/ScooterController.h"
#include "../Utils/Utils.h"

/**
 * This user interface class is used so that the customer ui and manager ui inherit functions from it, simplifying the
 * way the classes are implemented
 */
namespace ui {
    class UI {
        friend class Widgets;

    protected:
        shared_ptr<ctrl::ScooterController> controller;
    public:

        explicit UI(std::shared_ptr<ctrl::ScooterController> _controller)
                : controller(std::move(_controller)) {}


        virtual void mainMenu() const = 0;


        /**
         * function in the ui used to search scooters by their location
         */
        void searchByLocation() const {
            Widgets::printTitle("Search by Location");
            cout << "Location ->";
            string location;
            cin.ignore();
            getline(cin, location);
            cout << endl;

            auto matches = controller->searchByLocation(location);

            if (matches.empty()) {
                cout << "No matches found\n";
                return;
            }

            // Print matches as table
            Widgets::tableView(matches);
        }

        /**
         * @brief this function in the ui is used to filter the scooters by their commissioning date
         */
        void filterByCommissioningDate() const {
            Widgets::printTitle("Filter scooters by commission date");
            cout << "Commissioning Date ->";
            string commissioningDate;
            cin >> commissioningDate;
            cout << endl;

            if(!isDateFormatValid(commissioningDate)){
                cout << "Invalid date format\n";
                filterByCommissioningDate();
            }

            auto matches = controller->filterByCommissioningDate(commissioningDate);

            if (matches.empty()) {
                cout << "No matches found\n";
                return;
            }

            Widgets::tableView(matches);

        }

        /**
         * @brief this function in the ui is used to filter the scooters by their kilometers
         */
        void filterByKilometers() const {
            Widgets::printTitle("Filter scooters by kilometers");
            cout << "Kilometer ->";
            float kilometer;
            cin >> kilometer;
            cout << endl;

            auto matches = controller->filterByKilometer(kilometer);

            if (matches.empty()) {
                cout << "No matches found\n";
                return;
            }

            Widgets::tableView(matches);
        }
    };
}


#endif //OOP_L5_UI_H
