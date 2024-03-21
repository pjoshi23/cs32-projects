//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by Pranav on 11/17/23.
//

#include "PassengerDatabase.h"

namespace cs32 {

PassengerDatabase::PassengerDatabase() {
    // start with isLoaded = false by default
    isLoaded = false;
}

PassengerDatabase::~PassengerDatabase() {
    
    clearAllPassengers();
    
}

int PassengerDatabase::load(std::string filePath) {
    
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    
    // if no passengers were loaded, then isLoaded is false
    // means loading didn't work correctly
    if (recordCount == 0) {
        isLoaded = false;
    } else {
        isLoaded = true;
    }
    
    return( recordCount );
    
}

void PassengerDatabase::clearAllPassengers() {
    
    // delete each passenger pointer, then clear the vector
    for (size_t i = 0; i < passengers.size(); i++) {
        delete passengers.at(i);
    }
    
    passengers.clear();
    
}

bool PassengerDatabase::loaded() {
    
    return isLoaded;
    
}

Passenger* PassengerDatabase::getPassenger_byName(std::string name) {
    // loop over vector and if passenger's name is a match, return
    // otherwise return nullptr
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers.at(i)->getName() == name) {
            return passengers.at(i);
        }
    }
    
    return nullptr;
    
}

std::vector<Passenger*> PassengerDatabase::getPassengers() {
    
    return passengers;
        
}

std::vector<Passenger*> PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minFare) {
    
    // want to create vector of only passengers that satisfy criteria
    // loop through old vector
    // if passenger matches class, survived, and minFare, add to new vector
    // return new vector
    std::vector<Passenger*> newVec;
    
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers.at(i)->getClass() == paidClass) {
            if (passengers.at(i)->getSurvived() == survived && passengers.at(i)->getFare() > minFare) {
                newVec.push_back(passengers.at(i));
            }
        }
    }
    
    return newVec;
    
}

std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minFare) {
    // want to create vector of only passengers that satisfy criteria
    // loop through old vector
    // if passenger matches embarcation, survived, and minFare, add to new vector
    // return new vector
    std::vector<Passenger*> newVec;
    
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers.at(i)->getEmbarcation() == embarked) {
            if (passengers.at(i)->getSurvived() == survived && passengers.at(i)->getFare() > minFare) {
                newVec.push_back(passengers.at(i));
            }
        }
    }
    
    return newVec;
    
}

}
