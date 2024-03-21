//
//  Card.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Card.h"

namespace cs32
{

Card::Card()
{
    mSuit = Suit::HEARTS;
    mFace = Face::ACE;
}

Card::Card( Suit s, Face f )
{
    mSuit = s;
    mFace = f;
}

Suit Card::getSuit() const
{
    return( mSuit );
}

// TODO
// CS 32 Students need to complete this operation
void Card::setSuit( Suit s )
{
    mSuit = s;
}

Face Card::getFace() const
{
    return( mFace );
}

// TODO
// CS 32 Students need to complete this operation
void Card::setFace( Face f )
{
    mFace = f;
}

// TODO
// CS 32 Students need to complete this operation
int  Card::getValue() const
{
    int result = 0;
    
    if (mFace == Face::ACE) {
        return 1;
    } else if (mFace == Face::KING || mFace == Face::QUEEN || mFace == Face::JACK || mFace == Face::TEN) {
        return 10;
    } else {
        return (((int) mFace) + 1);
    }

    return( result );
}

std::string Card::to_string() const
{
    std::string result = "";
    switch( mFace )
    {
        case Face::ACE:
            result = "Ace of ";
            break;
        case Face::DEUCE:
            result = "Deuce of ";
            break;
        case Face::THREE:
            result = "Three of ";
            break;
        case Face::FOUR:
            result = "Four of ";
            break;
        case Face::FIVE:
            result = "Five of ";
            break;
        case Face::SIX:
            result = "Six of ";
            break;
        case Face::SEVEN:
            result = "Seven of ";
            break;
        case Face::EIGHT:
            result = "Eight of ";
            break;
        case Face::NINE:
            result = "Nine of ";
            break;
        case Face::TEN:
            result = "Ten of ";
            break;
        case Face::JACK:
            result = "Jack of ";
            break;
        case Face::QUEEN:
            result = "Queen of ";
            break;
        case Face::KING:
            result = "King of ";
            break;
    }
    
    
    // push s to the next suit...
    switch( mSuit )
    {
        case Suit::HEARTS:
            result += "Hearts";
            break;
        case Suit::CLUBS:
            result += "Clubs";
            break;
        case Suit::DIAMONDS:
            result += "Diamonds";
            break;
        case Suit::SPADES:
            result += "Spades";
            break;
    }
    return( result );
}


}

