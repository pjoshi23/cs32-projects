//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default STAND
    
    Choice c = Choice::STAND;
    // Situation for pair of ACE
    if (mCard1.getFace() == Face::ACE && mCard2.getFace() == Face::ACE) {
        c = Choice::SPLIT;
        return c;
    // Situation for pair of KING, QUEEN, JACK, or TEN
    } else if (isPair() && mCard1.getValue() == 10) {
        c = Choice::STAND;
        return c;
    // Situation for pair of NINE
    } else if (isPair() && mCard1.getFace() == Face::NINE) {
        if ((dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) || (dealerCard.getValue() >= 8 && dealerCard.getValue() <= 9)) {
            c = Choice::SPLIT;
            return c;
        } else {
            c = Choice::STAND;
            return c;
        }
    // Situation for pair of EIGHT
    } else if (isPair() && mCard1.getFace() == Face::EIGHT) {
        c = Choice::SPLIT;
        return c;
    // Situation for pair of SEVEN
    } else if (isPair() && mCard1.getFace() == Face::SEVEN) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 7) {
            c = Choice::SPLIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for pair of SIX
    } else if (isPair() && mCard1.getFace() == Face::SIX) {
        if (dealerCard.getValue() == 2) {
            c = Choice::SPLITHIT;
            return c;
        } else if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
            c = Choice::SPLIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for pair of FIVE
    } else if (isPair() && mCard1.getFace() == Face::FIVE) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 9) {
            c = Choice::DOUBLEHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for pair of FOUR
    } else if (isPair() && mCard1.getFace() == Face::FOUR) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 4) {
            c = Choice::HIT;
            return c;
        } else if (dealerCard.getValue() >= 5 && dealerCard.getValue() <= 6) {
            c = Choice::SPLITHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for pair of THREE
    } else if (isPair() && mCard1.getFace() == Face::THREE) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 3) {
            c = Choice::SPLITHIT;
            return c;
        } else if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 7) {
            c = Choice::SPLIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for pair of TWO
    } else if (isPair() && mCard1.getFace() == Face::DEUCE) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 3) {
            c = Choice::SPLITHIT;
            return c;
        } else if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 7) {
            c = Choice::SPLIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for ACE and EIGHT
    } else if (isSoft() && (mCard1.getFace() == Face::EIGHT || mCard2.getFace() == Face::EIGHT)) {
        c = Choice::STAND;
        return c;
    // Situation for ACE and SEVEN
    } else if (isSoft() && (mCard1.getFace() == Face::SEVEN || mCard2.getFace() == Face::SEVEN)) {
        if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLESTAND;
            return c;
        } else if (dealerCard.getValue() == 2 || (dealerCard.getValue() >= 7 && dealerCard.getValue() <= 8)) {
            c = Choice::STAND;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for ACE and SIX
    } else if (isSoft() && (mCard1.getFace() == Face::SIX || mCard2.getFace() == Face::SIX)) {
        if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLEHIT;
            return c;
        } else if (dealerCard.getValue() == 2 || (dealerCard.getValue() >= 7 && dealerCard.getValue() <= 8)) {
            c = Choice::HIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for ACE and FIVE
    } else if (isSoft() && (mCard1.getFace() == Face::FIVE || mCard2.getFace() == Face::FIVE)) {
        if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLEHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for ACE and FOUR
    } else if (isSoft() && (mCard1.getFace() == Face::FOUR || mCard2.getFace() == Face::FOUR)) {
        if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLEHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for ACE and THREE
    } else if (isSoft() && (mCard1.getFace() == Face::THREE || mCard2.getFace() == Face::THREE)) {
        if (dealerCard.getValue() >= 5 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLEHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation for ACE and TWO
    } else if (isSoft() && (mCard1.getFace() == Face::DEUCE || mCard2.getFace() == Face::DEUCE)) {
        if (dealerCard.getValue() >= 5 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLEHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation where total value of hand is 17
    } else if (mCard1.getValue() + mCard2.getValue() == 17) {
        c = Choice::STAND;
        return c;
    // Situation where total value of hand is 16
    } else if (mCard1.getValue() + mCard2.getValue() == 16) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
            return c;
        } else if (dealerCard.getValue() >= 7 && dealerCard.getValue() <= 8) {
            c = Choice::HIT;
            return c;
        } else {
            c = Choice::SURRENDERHIT;
            return c;
        }
    // Situation where total value of hand is 15
    } else if (mCard1.getValue() + mCard2.getValue() == 15) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
            return c;
        } else if (dealerCard.getValue() == 10) {
            c = Choice::SURRENDERHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation where total value of hand is 14
    } else if (mCard1.getValue() + mCard2.getValue() == 14) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation where total value of hand is 13
    } else if (mCard1.getValue() + mCard2.getValue() == 13) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation where total value of hand is 12
    } else if (mCard1.getValue() + mCard2.getValue() == 12) {
        if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation where total value of hand is 11
    } else if (mCard1.getValue() + mCard2.getValue() == 11) {
        c = Choice::DOUBLEHIT;
        return c;
    // Situation where total value of hand is 10
    } else if (mCard1.getValue() + mCard2.getValue() == 10) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 9) {
            c = Choice::DOUBLEHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation where total value of hand is 9
    } else if (mCard1.getValue() + mCard2.getValue() == 9) {
        if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLEHIT;
            return c;
        } else {
            c = Choice::HIT;
            return c;
        }
    // Situation where total value of hand is 8
    } else if (mCard1.getValue() + mCard2.getValue() == 8) {
        c = Choice::HIT;
        return c;
    }
    
    return( c );
}

// TODO CS 32 students need to complete this operation
bool Hand::isPair() const
{
    return (mCard1.getFace() == mCard2.getFace());
}

// TODO CS 32 students need to complete this operation
bool Hand::isSoft() const
{
    return (mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE);
}

bool Hand::isValid() const {
    return (
            !(
              (mCard1.getSuit() == mCard2.getSuit())
              &&
            (mCard1.getFace() == mCard2.getFace()))
            );
}



}
