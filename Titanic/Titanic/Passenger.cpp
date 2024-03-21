//
//  CSVFile.cpp
//  Titanic
//
//  Created by Howard Stahl on 7/1/23.
//

#include "Passenger.h"

namespace cs32
{

Passenger::Passenger() {
    
}

void Passenger::setName(std::string name) {
    mName = name;
}

std::string Passenger::getName() {
    return mName;
}

// go through different valid options and if none of them, set mEmbarked to not known
void Passenger::setEmbarcation(std::string e) {
    if (e == "C") {
        mEmbarked = Embarcation::CHERBOURG;
    } else if (e == "Q") {
        mEmbarked = Embarcation::QUEENSTOWN;
    } else if (e == "S") {
        mEmbarked = Embarcation::SOUTHHAMPTON;
    } else {
        mEmbarked = Embarcation::NOTKNOWN;
    }
}

// go through different valid options and if none of them, set mClass to not known
void Passenger::setClass(std::string c) {
    if (c == "1") {
        mClass = Class::FIRST;
    } else if (c == "2") {
        mClass = Class::SECOND;
    } else if (c == "3") {
        mClass = Class::THIRD;
    } else {
        mClass = Class::NOTKNOWN;
    }
}

// go through different valid options and if none of them, set mSurvived to not known
void Passenger::setSurvived(std::string s) {
    if (s == "1") {
        mSurvived = true;
    } else {
        mSurvived = false;
    }
}
void Passenger::setFare(std::string f) {
    mFare = std::stof(f);
}

Embarcation Passenger::getEmbarcation() {
    return mEmbarked;
}

Class Passenger::getClass() {
    return mClass;
}

bool Passenger::getSurvived() {
    return mSurvived;
}

double Passenger::getFare() {
    return mFare;
}

}
