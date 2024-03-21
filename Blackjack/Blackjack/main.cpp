#include "Card.h"
#include "Hand.h"
#include "Enums.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


int main()
{
       using namespace cs32;

    cout << "hello" << endl;
                Card ace( Suit::CLUBS, Face::ACE );
    Card ace2(Suit::HEARTS, Face::ACE);
               Card two( Suit::HEARTS, Face::DEUCE );
               Card three( Suit::DIAMONDS, Face::THREE );
               Hand h( ace, two );
               assert( h.isValid( ) );
               Hand h1( ace, ace );
               assert( h1.isValid( ) == false );
               Hand h2( three, three );
                Hand h3(ace, ace2);
               assert( h2.isValid( ) == false );
                assert(h3.isValid());
    cout << h.power(2, 5) << endl;
    cout << h.powerR(2, 5) << endl;
    
    
    
    

        cout << "all tests passed!" << endl;
        return( 0 );

   }
