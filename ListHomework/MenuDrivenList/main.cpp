#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

using namespace std;
using namespace cs32;

int main(){


List test;

test.addToRear("Apple");
test.addToRear("Banana");
test.addToRear("Pear");
test.addToRear("Strawberry");
test.addToRear("Kiwi");
test.addToRear("Cherry");
test.addToRear("Orange");
test.addToRear("Grape");
test.addToFront("Guava");

assert(test.size() == 9);



assert(test.position("Banana") == 2);
assert(test.position("Strawberry") == 4);
assert(test.position("Guava") == 0);
assert(test.position("Grape") == 8);
assert(test.position("Melon") == -1);


assert(test.before("Kiwi", "Orange") == true);
assert(test.before("Pear", "Apple") == false);
assert(test.before("Melon", "Cherry") == false);
assert(test.before("Cherry", "Melon") == false);


string element;
assert(test.get(1, element) == true);
assert(element == "Apple");
assert(test.get(10, element) == false);

assert(test.min() == "Apple");

    
    cout << test.printItems() << endl;
test.removeAllBiggerThan("Drake");
    cout << test.printItems() << endl;
assert(test.size() == 3);
assert(test.position("Apple") == 0);
assert(test.position("Cherry") == 2);


cout << "all tests passed!" << endl;
return( 0 );
}
