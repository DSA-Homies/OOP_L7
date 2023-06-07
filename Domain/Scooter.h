#ifndef OOP_L5_SCOOTER_H
#define OOP_L5_SCOOTER_H

#include <string>
#include <vector>

/**
 * This is the scooter entity class.
 * The status enum represents the state of the scooter at the current moment, so whether it is begin used by a user, it
 * is reserved, it is parked, it is awaiting, or it is decommissioned.
 */
using namespace std;
namespace domain {
    enum Status {
        PARKED = 0,
        RESERVED = 1,
        IN_USE = 2,
        AWAITING = 3,
        DECOMMISSIONED = 4
    };

    static vector<string> statusList = {
            "PARKED",
            "RESERVED",
            "IN_USE",
            "AWAITING",
            "DECOMMISSIONED"
    };

    class Scooter {
    public:

        [[nodiscard]] static string statusToStr(Status _status) { return statusList[_status]; }

        [[nodiscard]] static Status strToStatus(const string &_status) {
            for (int i = 0; i < statusList.size(); ++i)
                if (statusList[i] == _status)
                    return Status(i);

            return DECOMMISSIONED;
        }

        static bool isStatusValid(const string &_status) {
            for (const auto &i: statusList)
                if (i == _status)
                    return true;

            return false;
        }

    private:
        string id;
        string model;
        time_t commissioningDate;
        float kilometer;
        string location;
        Status status;

    public:

        //Constructors
        explicit Scooter(string id = "", string model = "", time_t commissioningDate = 0, float kilometer = 0.0,
                         string location = "",
                         Status status = DECOMMISSIONED);

        Scooter(string id, string model, const string &commissioningDate, float kilometer,
                string location, Status status = DECOMMISSIONED);

        //id getter
        [[nodiscard]] string getId() const;

        //id setter
        void setId(const string &id);

        //model getter
        [[nodiscard]] string getModel() const;

        //model setter
        void setModel(const string &model);

        //commissioning date getter
        [[nodiscard]] time_t getCommissioningDate() const;

        [[nodiscard]] string getCommissioningDateStr() const;

        //commissioning date setter
        void setCommissioningDate(time_t _commissioningDate);

        //commissioning date setter
        void setCommissioningDate(const string &_commissioningDate);

        //kilometer getter
        [[nodiscard]] float getKilometer() const;

        [[nodiscard]] string getKilometerStr() const;

        //kilometer setter
        void setKilometer(float kilometer);

        //location getter
        [[nodiscard]] string getLocation() const;

        //location setter
        void setLocation(const string &location);

        //status getter
        [[nodiscard]] Status getStatus() const;

        [[nodiscard]] string getStatusStr() const;

        //status setter
        void setStatus(Status status);

        //Overloaded operators
        bool operator==(const Scooter &other) const;

        bool operator!=(const Scooter &other) const;

        //transforms object to string
        [[nodiscard]] string toString() const;

        //makes a list of strings from the objects attributes
        [[nodiscard]] vector<string> toList() const;

        //make a string representing the details of the object
        [[nodiscard]] string details() const;
    };

}
#endif //OOP_L5_SCOOTER_H
