//
//  DataCollectorCallback.hpp
//  Titanic
//
//  Created by Howard Stahl on 7/1/23.
//

#ifndef PASSENGER_H
#define PASSENGER_H

#include "Enums.h"
#include <string>

namespace cs32 {

class Passenger {

public:
    Passenger();
    
    void setName(std::string n);
    std::string getName();
    
    void setEmbarcation(std::string e);
    void setClass(std::string c);
    void setSurvived(std::string s);
    void setFare(std::string f);
    
    Embarcation getEmbarcation();
    Class getClass();
    bool getSurvived();
    double getFare();
    
private:
    Class mClass;
    Embarcation mEmbarked;
    std::string mName;
    bool mSurvived;
    double mFare;
};

}

#endif /* Passenger.h */
