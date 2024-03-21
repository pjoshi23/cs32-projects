//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Pranav on 11/25/23.
//

#include "PassengerOutputTable.h"
#include <iostream>

namespace cs32 {

PassengerOutputTable::PassengerOutputTable(std::vector<Passenger*> passengers) {
    // set mField to default value
    
    mPassengerList = passengers;
    mField = Field::NOVALUE;
    
}

void PassengerOutputTable::setOutputField(Field f) {
    mField = f;
}

void PassengerOutputTable::setDescription(std::string description) {
    mDescription = description;
}

Field PassengerOutputTable::getOutputField() {
    return mField;
}


std::string PassengerOutputTable::getDescription() {
    return mDescription;
}

void PassengerOutputTable::display() {
    // clear mRows initially
    mRows.clear();
    
    // if field == NOVALUE, don't display anything
    if (mField == Field::NOVALUE) {
        return;
    }
    
    // start with byFare
    if (mField == Field::BYFARE) {
        mDescription = "List of passengers by fare";
        
        // create all output rows first, set descriptions
        OutputTableRow first;
        first.setDescription("Not Known-");
        OutputTableRow second;
        second.setDescription("$1-$10-");
        OutputTableRow third;
        third.setDescription("$10-$25-");
        OutputTableRow fourth;
        fourth.setDescription("$25-$50-");
        OutputTableRow fifth;
        fifth.setDescription(">$50-");
        
        // loop over the passengers, and for each passenger
        // check which output row they would belong to for fare
        // increment total and, if they survived, increment survived
        for (size_t i = 0; i < mPassengerList.size(); i++) {
            if (mPassengerList.at(i)->getFare() == 0) {
                first.setTotal(first.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    first.setSurvived(first.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getFare() > 0 && mPassengerList.at(i)->getFare() <= 10) {
                second.setTotal(second.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    second.setSurvived(second.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getFare() > 10 && mPassengerList.at(i)->getFare() <= 25) {
                third.setTotal(third.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    third.setSurvived(third.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getFare() > 25 && mPassengerList.at(i)->getFare() <= 50) {
                fourth.setTotal(fourth.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    fourth.setSurvived(fourth.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getFare() > 50) {
                fifth.setTotal(fifth.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    fifth.setSurvived(fifth.getSurvived()+1);
                }
            }
        }
        
        // add all the rows to mRows
        mRows.push_back(first);
        mRows.push_back(second);
        mRows.push_back(third);
        mRows.push_back(fourth);
        mRows.push_back(fifth);
    } else if (mField == Field::BYCLASS) {
        mDescription = "List of passengers by class";

        // create all the output rows, and set descriptions
        OutputTableRow first;
        first.setDescription("Not Known-");
        OutputTableRow second;
        second.setDescription("First Class-");
        OutputTableRow third;
        third.setDescription("Second Class-");
        OutputTableRow fourth;
        fourth.setDescription("Third Class-");
        
        // loop over the passengers, and for each passenger
        // check which output row they would belong to for class
        // increment total and, if they survived, increment survived
        for (size_t i = 0; i < mPassengerList.size(); i++) {
            if (mPassengerList.at(i)->getClass() == Class::NOTKNOWN) {
                first.setTotal(first.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    first.setSurvived(first.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getClass() == Class::FIRST) {
                second.setTotal(second.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    second.setSurvived(second.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getClass() == Class::SECOND) {
                third.setTotal(third.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    third.setSurvived(third.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getClass() == Class::THIRD) {
                fourth.setTotal(fourth.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    fourth.setSurvived(fourth.getSurvived()+1);
                }
            }
        }
        
        // add all the rows to mRows
        mRows.push_back(second);
        mRows.push_back(third);
        mRows.push_back(fourth);
        mRows.push_back(first);
    } else if (mField == Field::BYEMBARCATION) {
        mDescription = "List of passengers by embarcation";
        
        // create all the output rows and set their descriptions
        OutputTableRow first;
        first.setDescription("Not Known-");
        OutputTableRow second;
        second.setDescription("Cherbourg-");
        OutputTableRow third;
        third.setDescription("Queenstown");
        OutputTableRow fourth;
        fourth.setDescription("Southampton-");
        
        // loop over the passengers, and for each passenger
        // check which output row they would belong to for embarcation
        // increment total and, if they survived, increment survived
        for (size_t i = 0; i < mPassengerList.size(); i++) {
            if (mPassengerList.at(i)->getEmbarcation() == Embarcation::NOTKNOWN) {
                first.setTotal(first.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    first.setSurvived(first.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getEmbarcation() == Embarcation::CHERBOURG) {
                second.setTotal(second.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    second.setSurvived(second.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getEmbarcation() == Embarcation::QUEENSTOWN) {
                third.setTotal(third.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    third.setSurvived(third.getSurvived()+1);
                }
            } else if (mPassengerList.at(i)->getEmbarcation() == Embarcation::SOUTHHAMPTON) {
                fourth.setTotal(fourth.getTotal() + 1);
                if (mPassengerList.at(i)->getSurvived() == 1) {
                    fourth.setSurvived(fourth.getSurvived()+1);
                }
            }
        }
        
        // add the rows to mRows
        mRows.push_back(second);
        mRows.push_back(third);
        mRows.push_back(fourth);
        mRows.push_back(first);
    }
    
    // output description
    std::cout << mDescription << std::endl;
    // for each row in mRows, call the row'ss display method
    for (size_t i = 0; i < mRows.size(); i++) {
        mRows.at(i).display();
    }
}

size_t PassengerOutputTable::rowCount() {
    return mRows.size();
}

OutputTableRow PassengerOutputTable::getRow(int index) {
    return mRows.at(index);
}

}
