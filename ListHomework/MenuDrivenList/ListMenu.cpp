//// Menu.cpp : Defines the entry point for the console application.
////
//
//#include <iostream>
//#include <string>
//#include <cassert>
//#include "List.h"
//#include "ListNode.h"
//
//using namespace std;
//using namespace cs32;
//
//enum class CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };
//
//CHOICE menu();
//
//int main(int argc, char* argv[]) {
//    
//	string value;
//	List list;
//    List list2;
//
////	CHOICE choice;
////	do {
////		choice = menu();
////		switch( choice ) {
////        case CHOICE::MAKEEMPTY:
////			list.makeEmpty();
////			break;
////        case CHOICE::ISEMPTY:
////			if (list.isEmpty()) {
////				cout << "list is empty" << endl;
////			}
////			else {
////				cout << "list is not empty" << endl;
////			}
////			break;
////        case CHOICE::DELETE:
////			cout << "Please provide a string to remove: ";
////			cin  >> value; 
////			list.deleteItem( value );
////			break;
////        case CHOICE::ADDTOFRONT:
////			cout << "Please provide a string to insert in front: ";
////			cin  >> value; 
////			list.addToFront( value );
////			break;
////        case CHOICE::ADDTOREAR:
////            cout << "Please provide a string to insert in rear: ";
////            cin  >> value;
////            list.addToRear( value );
////            break;
////        case CHOICE::FIND:
////			cout << "Please provide a string to find: ";
////			cin  >> value;
////            cout.setf( ios::boolalpha );
////            cout << list.findItem( value ) << endl;
////            cout.unsetf( ios::boolalpha );
////			break;
////        case CHOICE::PRINT:
////            cout << list.printItems() << endl;;
////			break;
////        case CHOICE::OPERATOR:
////            list2 = list;
////            cout << "second list now:" << endl;
////            cout << list2.printItems() << endl;
////            break;
////        case CHOICE::QUIT:
////            break;
////	}	
////
////	} while (choice != CHOICE::QUIT);
//
//        // Test 1: Check the size of an empty list
//        size_t emptySize = list.size();
//        assert(emptySize == 0);
//
//        // Test 2: Add some elements to the list
//        list.addToRear("hi");  // Assuming your List class has an insert method
//        list.addToRear("hello");
//        list.addToRear("hola");
//
//        // Check the size after adding elements
//        size_t nonEmptySize = list.size();
//        assert(nonEmptySize == 3);
//
//        // Test 3: Remove elements from the list
//        list.deleteItem("hello");  // Assuming your List class has a remove method
//
//        // Check the size after removing an element
//        size_t newSize = list.size();
//        assert(newSize == 2);
//    
//    list2.addToRear("apple"); // Assuming your List class has an insert method
//    list2.addToRear("banana");
//    list2.addToRear("cherry");
//    list2.addToRear("date");
//    list2.addToRear("apple"); // Adding another "apple"
//
//    // Test 1: Find the position of an existing element
//    int pos1 = list2.position("banana");
//    assert(pos1 == 1); // "banana" should be at index 1
//
//    // Test 2: Find the position of the first occurrence of "apple"
//    int pos2 = list2.position("apple");
//    assert(pos2 == 0); // The first "apple" should be at index 0
//
//    // Test 3: Find the position of an element that occurs multiple times
//    int pos3 = list2.position("apple");
//    assert(pos3 == 0); // It should still return the position of the first "apple"
//
//    // Test 4: Find the position of an element not in the list
//    int pos4 = list2.position("grape");
//    assert(pos4 == -1); // "grape" is not in the list, so it should return -1
//
//    // Test 5: Find the position in an empty list
//    List emptyList;
//    int pos5 = emptyList.position("pear");
//    assert(pos5 == -1); // The list is empty, so it should return -1
//
//    // Additional test cases can be added based on specific scenarios and edge cases.
//    
//    List list3;
//        list3.addToRear("apple");  // Assuming your List class has an insert method
//        list3.addToRear("banana");
//        list3.addToRear("cherry");
//        list3.addToRear("date");
//
//        // Test 1: Check if "apple" is before "banana"
//        bool result1 = list3.before("apple", "banana");
//        assert(result1 == true); // "apple" is before "banana" in the list
//    cout << "1" << endl;
//
//        // Test 2: Check if "date" is before "apple"
//        bool result2 = list3.before("date", "apple");
//        assert(result2 == false); // "date" is before "apple" in the list
//    cout << "2" << endl;
//
//        // Test 3: Check if "banana" is before "apple"
//        bool result3 = list3.before("banana", "apple");
//        assert(result3 == false); // "banana" is not before "apple" in the list
//    cout << "3" << endl;
//
//        // Test 4: Check if "grape" is before "date" (neither are in the list)
//        bool result4 = list3.before("grape", "date");
//        assert(result4 == false); // "grape" and "date" are not in the list
//    cout << "4" << endl;
//
//        // Test 5: Check if "banana" is before "banana" (same value)
//        bool result5 = list3.before("banana", "banana");
//        assert(result5 == false); // "banana" is not before itself
//    cout << "5" << endl;
//
//        // Test 6: Check if "banana" is before "grape" (grape is not in the list)
//        bool result6 = list3.before("banana", "grape");
//        assert(result6 == true); // "grape" is not in the list
//    cout << "6" << endl;
//
//    // Remember to include proper error handling if your List class allows for exceptional conditions.
//    
//    List myList;
//        myList.addToRear("apple");  // Assuming your List class has an insert method
//        myList.addToRear("banana");
//        myList.addToRear("cherry");
//
//        // Test 1: Get an element at a valid position (0)
//        std::string data1;
//        bool resulta = myList.get(0, data1);
//        assert(resulta == true); // Position 0 exists
//        assert(data1 == "apple"); // "apple" is at position 0
//
//        // Test 2: Get an element at a valid position (2)
//        std::string data2;
//        bool resultb = myList.get(2, data2);
//        assert(resultb == true); // Position 2 exists
//        assert(data2 == "cherry"); // "cherry" is at position 2
//
//        // Test 3: Get an element at an invalid position (out of bounds)
//        std::string data3;
//        bool resultc = myList.get(3, data3);
//        assert(resultc == false); // Position 3 is out of bounds
//
//        // Test 4: Get an element when the list is empty
//        List emptyList2;
//        std::string data4;
//        bool resultd = emptyList2.get(0, data4);
//        assert(resultd == false); // The list is empty
//    
//    List myList2;
//        myList2.addToRear("apple");  // Assuming your List class has an insert method
//        myList2.addToRear("banana");
//        myList2.addToRear("cherry");
//
//        // Test 1: Get the minimum item in a non-empty list
//        std::string min1 = myList2.min();
//        assert(min1 == "apple"); // "apple" is the smallest item in the list
//
//        // Test 2: Get the minimum item in a list with only one element
//        List singleItemList;
//        singleItemList.addToRear("grape");
//        std::string min2 = singleItemList.min();
//        assert(min2 == "grape"); // The list contains only "grape"
//
//        // Test 3: Get the minimum item in an empty list
//        List emptyList3;
//        std::string min3 = emptyList3.min();
//        assert(min3 == ""); // The list is empty, so the result should be an empty string
//
//        // Test 4: Get the minimum item in a list with mixed case elements
//        List mixedCaseList;
//        mixedCaseList.addToRear("Apple");
//        mixedCaseList.addToRear("banana");
//        mixedCaseList.addToRear("cherry");
//        std::string min4 = mixedCaseList.min();
//        assert(min4 == "Apple");
//    
//    List myList3;
//    myList3.addToRear("apple");  // Assuming your List class has an insert method
//    myList3.addToRear("banana");
//    myList3.addToRear("cherry");
//    myList3.addToRear("date");
//    myList3.addToRear("grape");
//    
//    // Test 1: Remove items greater than "banana"
//    std::string target1 = "banana";
//    myList3.removeAllBiggerThan(target1);
//    cout << myList3.size() << endl;
//    assert(myList3.size() == 2); // After removal, there should be 2 items left
//    assert(myList3.position("apple") == 0); // "apple" should be at position 0
//    assert(myList3.position("banana") == 1); // "banana" should be at position 1
//
//    // Test 2: Remove items greater than "grape" (no items to remove)
//    std::string target2 = "grape";
//    myList.removeAllBiggerThan(target2);
//    assert(myList3.size() == 2); // No items removed, the list size remains the same
//
//    // Test 3: Remove items greater than "date" (all items to be removed)
//    std::string target3 = "date";
//    myList3.removeAllBiggerThan(target3);
//    assert(myList3.size() == 0); // All items removed, the list is now empty
//
//    // Test 4: Remove items greater than an empty string (remove all items)
//    std::string target4 = "";
//    myList3.addToRear("apple");
//    myList3.addToRear("banana");
//    myList3.addToRear("cherry");
//    myList3.addToRear("date");
//    myList3.addToRear("grape");
//    myList3.removeAllBiggerThan(target4);
//    assert(myList3.size() == 0); // All items removed, the list is now empty
//
//    // Test 5: Remove items when the list is empty (no items to remove)
//    List emptyList4;
//    std::string target5 = "apple";
//    emptyList4.removeAllBiggerThan(target5);
//    assert(emptyList4.size() == 0); // No items to remove, the list remains empty
//
//    // Additional test cases can be added based on specific scenarios and edge cases.
//
//    // Remember to include proper error handling if your List class allows for exceptional conditions.    
//    cout << "passed all test cases!" << endl;
//    
//	return( 0 );
//}
//
//CHOICE menu() {
//	string s;
//	CHOICE result;
//	cout << "(M)akeEmpty I(s)Empty (D)elete (A)ddToFront (R)AddtoRear  (F)ind (P)rint (=) (Q)uit: " << endl;
//	cin  >> s;
//    char choice = s.at( 0 );
//	switch( choice ) {
//	case 'M':
//	case 'm':
//		result = CHOICE::MAKEEMPTY;
//		break;
//    case 'D':
//    case 'd':
//        result = CHOICE::DELETE;
//        break;
//	case 'S':
//	case 's':
//		result = CHOICE::ISEMPTY;
//		break;
//    case 'A':
//    case 'a':
//        result = CHOICE::ADDTOFRONT;
//        break;
//	case 'R':
//	case 'r':
//		result = CHOICE::ADDTOREAR;
//		break;
//	case 'F':
//	case 'f':
//		result = CHOICE::FIND;
//		break;
//	case 'Q':
//	case 'q':
//		result = CHOICE::QUIT;
//		break;
//	case 'P':
//	case 'p':
//		result = CHOICE::PRINT;
//		break;
//    case '=':
//        result = CHOICE::OPERATOR;
//        break;
//    default:
//        result = CHOICE::QUIT;
//        break;
//	}
//
//	return( result );
//}
