//
//  PassengerDatabase.h
//  Titanic
//
//  Created by Pranav on 11/17/23.
//

#ifndef PassengerDatabase_h
#define PassengerDatabase_h

#include <string>
#include <vector>
#include <map>
#include "Passenger.h"
#include "CSVFile.h"
#include <iostream>

namespace cs32 {

class PassengerDatabase : public DataCollectorCallback {
    
public:
    PassengerDatabase();
    ~PassengerDatabase();
    
    int load(std::string filePath);
    void clearAllPassengers();
    bool loaded();
    
    Passenger* getPassenger_byName(std::string name);
    std::vector<Passenger*> getPassengers();
    
    std::vector<Passenger*> getPassengers_byClass(Class paidClass, bool survived, double minFare);
    std::vector<Passenger*> getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minFare);
    
//    size_t getTotal() {
//        return passengers.size();
//    }
//    
//    void display() {
//        for (size_t i = 0; i < passengers.size(); i++) {
//            std::cout << passengers.at(i)->getName() << "x" << std::endl;
//        }
//    }
    
    virtual void csvData(std::map<std::string, std::string> row) {
        // trying to make a Passenger object based on the map
        
        Passenger *p = new Passenger();
        
        p->setName(row["name"]);
        
        // if embarked in map isn't a valid value, set to not known
        if (row["embarked"] != "C" && row["embarked"] != "S" && row["embarked"] != "Q") {
            p->setEmbarcation("NOTKNOWN");
        } else {
            p->setEmbarcation(row["embarked"]);
        }
        
        // if class in map isn't a valid value, set to not known
        if (row["pclass"] != "1" && row["pclass"] != "2" && row["pclass"] != "3") {
            p->setClass("NOTKNOWN");
        } else {
            p->setClass(row["pclass"]);
        }
        
        p->setSurvived(row["survived"]);
        
        // if fare in map isn't a valid value, set to not known
        if (row["fare"] == "") {
            p->setFare("0");
        } else {
            p->setFare(row["fare"]);
        }
        
        // add the passenger to the vector
        passengers.push_back(p);
        
    }
    
private:
    std::vector<Passenger*> passengers;
    bool isLoaded;
    
};

}


#endif /* PassengerDatabase_h */
