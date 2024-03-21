#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

size_t List::size() const {
    if (isEmpty()) {
        // if its empty --> size = 0
        return 0;
    } else {
        ListNode *curr = head;
        // pointer points to head node
        int counter = 0;
        while (curr != nullptr) {
            // while current node not pointing to null, increment count
            counter++;
            
            // increment current --> make current point to current's next
            curr = curr->getNext();
        }
        
        return counter;
    }
}

int List::position( const std::string& data ) const {
    // current points to head node
    ListNode *curr = head;
    int counter = 0;
    
    while (curr != nullptr) {
        // if current element data element == data parameter, return
        if (curr->getElement() == data) {
            return counter;
        }
        
        // increment counter and current node
        counter++;
        curr = curr->getNext();
    }
    
    // if data not found in list, return -1
    return -1;
}

bool List::before( const std::string& before, const std::string& after ) const {
    // start them both at -1 --> index not possible
    int bpos = -1;
    int apos = -1;
    int counter = 0;
    
    // counter initialized to head node
    ListNode *curr = head;
    
    while (curr != nullptr) { // while current != nullptr
        if (curr->getElement() == before && bpos == -1) {
            // if element matches before, set before index
            bpos = counter;
        }
        
        if (curr->getElement() == after) {
            // if element matches after, set after index
            apos = counter;
        }
        
        // increment counter and current node
        counter++;
        curr = curr->getNext();
    }
    
    // make sure that before and after are both non-sentinel values
    // also that before < after, then return true
    return (bpos < apos && bpos != -1 && apos != -1);
}

bool List::get( int i, std::string& data ) const {
    
    // intitialize counter and current node to be head
    int counter = 0;
    ListNode *curr = head;
    
    
    while (curr != nullptr) {
        // if counter variable matches i (index)
        if (counter == i) {
            // set data to be element, then return
            data = curr->getElement();
            return true;
        }
        
        // increment counter and current node
        counter++;
        curr = curr->getNext();
    }
    
    // return false if index not in linked list
    return false;
}

std::string List::min() const {
    // if empty, return empty string
    if (size() == 0) {
        return "";
    }
    
    // initialize current node to head, and minsofar to element in head
    ListNode *curr = head;
    string minSoFar = curr->getElement();
    
    // set current to nextVal
    curr = curr->getNext();
    
    while (curr != nullptr) {
        // if current element < minsofar, set minsofar to element
        if (curr->getElement() < minSoFar) {
            minSoFar = curr->getElement();
        }
        
        // increment current node
        curr = curr->getNext();
    }
    
    return minSoFar;
}

void List::removeAllBiggerThan( const std::string & data ) {
    // if empty, nothing to remove, so immediately return
    if (isEmpty()) {
        return;
    }
    
    // start from the top
    // if not empty and head element > dataVal
    while (head != nullptr && head->getElement() > data) {
        // initialize node temp
        // set head to head's next
        // delete old head
        ListNode *temp = head;
        head = head->getNext();
        delete temp;
    }
    
    // initialize curr node to head
    ListNode *curr = head;
    
    while (curr != nullptr) {
        
        // initialize next to be curr's next node
        ListNode *next = curr->getNext();
        
        if (next != nullptr && next->getElement() > data) {
                // intiialize temp to be the same as next
                // set curr's next to be next's next --> cur next out of the linked list
                // delete next
                ListNode *temp = next;
                curr->setNext(next->getNext());
                delete temp;
        } else {
            // increment current node
            curr = curr->getNext();
        }
    }
}

}


