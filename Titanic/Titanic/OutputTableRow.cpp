//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Pranav on 11/25/23.
//

#include "OutputTableRow.h"
#include <iostream>

namespace cs32 {

OutputTableRow::OutputTableRow() {
    // set member variables to default values
    mDescription = "";
    mSurvived = 0;
    mTotal = 0;
    
}

void OutputTableRow::setDescription(std::string description) {
    mDescription = description;
}

void OutputTableRow::setSurvived(int survived) {
    mSurvived = survived;
}

void OutputTableRow::setTotal(int total) {
    mTotal = total;
}

std::string OutputTableRow::getDescription() {
    return mDescription;
}

int OutputTableRow::getSurvived() {
    return mSurvived;
}

int OutputTableRow::getTotal() {
    return mTotal;
}

double OutputTableRow::getPercentage() {
    // account for if 0, so getPercentage doesn't return NaN
    if (mTotal == 0) {
        return 0;
    }
    
    return (static_cast<double>(mSurvived))/mTotal;
}

void OutputTableRow::display() {
    std::cout << mDescription << " " << mSurvived << "/" << mTotal << " " << getPercentage() << std::endl;
}

}
