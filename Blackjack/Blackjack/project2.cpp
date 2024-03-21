//
//  project2.cpp
//  Blackjack
//
//  Created by Pranav on 10/16/23.
//

#ifndef PROJECT2_CPP
#define PROJECT2_CPP

#include <stdio.h>
#include <string>

using namespace std;

int modulo( unsigned int m, unsigned int n ) {
    return m%n;
}

int occurrences( int number, int d ) {
    if (number == 0) {
        return 0;
    }
    
    int counter = 0;
    if (number%10 == d) {
        counter = 1;
    }
    return counter + occurrences(number/10, d);
}

string lucky7s( string s ) {
    string newString = "";
    for (int i = 0; i < s.size() - 1; i++) {
        if (s.at(i) == s.at(i+1)) {
            newString += s.at(i);
            newString += "77";
        }
    }
    return newString;
    
}

bool combinations( int array[ ], int size, int target ) {
    if (size == 1) {
        if (array[0] == target) {
            return true;
        } else {
            return false;
        }
    }
    
    return (combinations(array, size-1, target-array[sizeof(array)/sizeof(array[0]) - size]) || combinations(array, size-1, target));
    
}

#endif
