#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>
#include <iostream>

namespace cs32 {

template <typename Type>
Deque<Type>::Deque()
{
    head = nullptr;
    tail = nullptr;
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    return head == nullptr;
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->getNext() != nullptr) {
        delete head->getNext();
    }
    
    delete head;
}

template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    if (isEmpty()) {
        DequeNode<Type> *node = new DequeNode<Type>(data);
        head = node;
        tail = node;
    } else {
        DequeNode<Type> *node = new DequeNode<Type>(data);
        node->setNext(head);
        head->setPrevious(node);
        head = node;
    }
    
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    if (isEmpty()) {
        DequeNode<Type> *node = new DequeNode<Type>(data);
        head = node;
        tail = node;
    } else {
        DequeNode<Type> *node = new DequeNode<Type>(data);
        tail->setNext(node);
        node->setPrevious(tail);
        tail = node;
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    
    if (isEmpty()) {
        return;
    } else {
        DequeNode<Type> *node = head;
        head = head->getNext();
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->setPrevious(nullptr);
        }
        delete node;
    }
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    DequeNode<Type> *node = head;
    while (node != nullptr) {
        if (node->getElement() == data) {
            if (node->getPrevious() != nullptr) {
                node->getPrevious()->setNext(node->getNext());
            } else {
                head = node->getNext();
            }
            
            if (node->getNext() != nullptr) {
                node->getNext()->setPrevious(node->getPrevious());
            } else {
                tail = node->getPrevious();
            }
            delete node;
            return true;
        }
        node = node->getNext();
    }
    
    return( false );
}


template <typename Type>
Type Deque<Type>::front( ) const
{
    Type result = Type();
    if (head != nullptr) {
        result = head->getElement();
    }
    return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    Type result = Type();
    if (tail != nullptr) {
        result = tail->getElement();
    }
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    if (isEmpty()) {
        return;
    } else {
        DequeNode<Type> *node = tail;
        tail = tail->getPrevious();
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->setNext(nullptr);
        }
        delete node;
    }

}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}


template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    string s;
    
    DequeNode<Type> *node = head;
    while (node != nullptr) {
        s += to_string(node->getElement());
        s += "->";
        
        node = node->getNext();
    }
    
    return( s );
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    
    makeEmpty();
    
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }

	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    DequeNode<Type> *node = head;
    while (node != nullptr) {
        result++;
        node = node->getNext();
    }

    return( result );
}

template <typename Type>
bool Deque<Type>::find(const Type& data) {
    DequeNode<Type> *curr = head;
    while (curr != nullptr) {
        if (curr->getElement() == data) {
            return true;
        }
        
        curr = curr->getNext();
    }
    
    return false;
}


template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    DequeNode<Type> *node = head;
    int counter = 0;
    while (node != nullptr) {
        
        if (counter == i) {
            data = node->getElement();
            return true;
        }
        counter++;
        node = node->getNext();
    }

    return( false );
}

}


#endif
