#include "Garage.h"

namespace cs32
{


Garage::Garage( size_t capacity )
{
    mCapacity = capacity;
}

// put something in the garage
// silently, it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    if (mDeque.size() >= mCapacity) {
        mDeque.deleteRear();
        mDeque.addToFront(s);
        return true;
    } else {
        mDeque.addToFront(s);
        return( false );
    }

    
}

bool Garage::tossOut( std::string s )
{
    if (mDeque.find(s)) {
        mDeque.deleteItem(s);
        return true;
    }

    return( false );
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    if (mDeque.find(s)) {
        mDeque.deleteItem(s);
        mDeque.addToFront(s);
        return true;
    }

    return( false );
}

// is it in the garage?
bool Garage::find( std::string s )
{
    return( mDeque.find(s) );
}

// how much can this garage maximally hold?
size_t Garage::capacity()
{
    return mCapacity;
}
// how much is in this garage right now?
size_t Garage::size( )
{
    return mDeque.size();
}

std::string Garage::printItems( )
{
    return mDeque.printItems();
}


}
