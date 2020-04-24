#ifndef ASSIGNMENT1_TLIST_H
#define ASSIGNMENT1_TLIST_H

#endif //ASSIGNMENT1_TLIST_H

#include <iostream>
#include <utility>
#include "tnode.h"

template <typename T>
class TList
{
    friend class TListIterator<T>;


public:
    TList();				// Create empty linked list
    TList(T val, int num);		// Create list with num copies of val
    ~TList();				// Destructor
    TList(const TList& L);		// Copy constructor
    TList& operator=(const TList& L);	// Copy assignment operator
    TList(TList && L);			// Move constructor
    TList& operator=(TList && L);	// Move assignment operator

    bool IsEmpty() const;		// Checks to see whether list is empty
    void Clear();			// Clear out list, reset to empty
    int GetSize() const;			// Return the size of the list

    void InsertFront(const T& d);	// Insert data d as first element
    void InsertBack(const T& d);		// Insert data d as last element
    void RemoveFront();			// Remove first element of list
    void RemoveBack();			// Remove last element of list

    T& GetFirst() const;			// Return first element of list
    T& GetLast() const;			// Return last element of list

    TListIterator<T> GetIterator() const;    // Return iterator to first item
    TListIterator<T> GetIteratorEnd() const; // Return iterator to last item

    void Insert(TListIterator<T> pos, const T& d);

    TListIterator<T> Remove(TListIterator<T> pos);

    void Print(std::ostream& os, char delim = ' ') const;

private:
    Node<T>* first;		// pointer to first node in list
    Node<T>* last;		// pointer to last node in list
    int size;			// number of nodes in the list
    static T dummy;		// dummy object, for empty list data returns
    //  assuming type T has default construction

};

template <typename T>
T TList<T>::dummy;		// initialization of static member

template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2);

template <typename T>
class TListIterator
{
    friend class TList<T>;

public:
    TListIterator();			// default constructor
    bool HasNext() const;		// next item available?
    bool HasPrevious() const;		// previous item available?
    TListIterator<T> Next();		// advance to next item
    TListIterator<T> Previous();		// move to previous item
    T& GetData() const;			// return data element of current node

private:
    Node<T>* ptr;		// pointer to current list item
};

#include "tlist.hpp"		// bring in definition file here
