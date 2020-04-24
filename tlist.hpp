// Christelle Nieves
// 01/24/2020

#ifndef ASSIGNMENT1_TNODE_H
#define ASSIGNMENT1_TNODE_H

#endif //ASSIGNMENT1_TNODE_H

#include <iostream>

using namespace std;

// **********************************************************
// * Function name: TList()
// * Default Constructor. *
// * Initializes an empty linked list. *
// **********************************************************
template<typename T>
TList<T>::TList()
{
	// An empty list will have null pointers and size 0.
    first = last = nullptr;
    size = 0;
}

// **********************************************************
// * Function name:TList()
// * Constructor.
// * Initializes an empty list with num copies of val. *
// **********************************************************
template<typename T>
TList<T>::TList(T val, int num)
{
	// Start size at 0.
    size = 0;

    if (num == 0)
    {
    	// If 0 is passed in as num, we will have an empty list.
        first = last = nullptr;
        return;
    }

    first = new Node<T>(val); // set the first node.
    size++; // increment the size because we created first node.

    Node<T> * current = first; // we will use this to iterate

    for (int i = 0; i < num - 1; i++)
    {
        current->next = new Node<T>(val);
        current->next->prev = current;
        size++; // increment size each time we make new node.
        current = current->next; // advance to the next node.

        if (i + 1 == num - 1)
        {
        	// set the last node
            last = current;
        }
    }
}

// **********************************************************
// * Function name: ~TList() *
// * Destructor *
// * Clears a linked list of all its nodes *
// **********************************************************
template<typename T>
TList<T>::~TList()
{
    Clear();
}

// **********************************************************
// * Function name: TList()
// * Copy Constructor. *
// * Creates a deep copy of the linked list that is passed in.*
// **********************************************************
template<typename T>
TList<T>::TList(const TList<T>& L)
{
    first = last = nullptr; // set pointers to null
    *this = L; // copy over the list that was passed in
    size = L.size; // set the new size
}

// **********************************************************
// * Function name: operator=()
// * Copy assignment operator. *
// * Used to assign a copy of linked list that is passed in. *
// **********************************************************
template<typename T>
TList<T>& TList<T>::operator = (const TList<T>& L)
{
	// Make sure its not already equal to the input list
    if (this != &L) {
    	// Clear the list if its non-null
        if (first != nullptr)
        {
            Clear();
        }

        // Create 2 nodes, one for the new copy and one for the original
        Node<T> * copy = nullptr, *orig = L.first;

        // Loop through each node in the input list
        while (orig != nullptr)
        {
        	// If we have an empty list
            if (first == nullptr)
            {
                first = last = copy = new Node<T>(orig->data);
            }
            else
			{
            	// If the list is non-empty, copy over the pointers from the original
                copy->next = new Node<T>(orig->data);
                copy->prev = orig->prev;

                // Advance to the next copy node
                copy = copy->next;
            }
            // Advance to the next original node
            orig = orig->next;
        } // end while
    } // end if

    return *this;
}

// **********************************************************
// * Function name: TList()
// * Move Constructor. *
// * Moves all contents from parameter list to the current list.*
// **********************************************************
template<typename T>
TList<T>::TList(TList<T> && L)
{
	// Set our variables to those of the input list L
	// Set L to null since we're moving it
    size = L.size;
    L.size = 0;
    first = L.first;
    L.first = nullptr;
    last = L.last;
    L.last = nullptr;
}

// **********************************************************
// * Function name: operator=()
// * Move assignment operator. *
// * Assigns the values of the parameter list to current list.*
// * Clears the parameter list after the assignment. *
// **********************************************************
template<typename T>
TList<T> & TList<T>::operator = (TList<T> && L)
{
    // Free the memory of this object
    Clear();

    // Assign our values to L values
    this->first = L.first;
    this->last = L.last;
    this->size = L.size;

    // set L to null
    L.first = L.last = nullptr;
    L.size = 0;

    return *this;
}

// **********************************************************
// * Function name: IsEmpty()
// * Returns true if linked list is Empty. False otherwise. *
// **********************************************************
template<typename T>
bool TList<T>::IsEmpty() const
{
    return GetSize() == 0;
}

// **********************************************************
// * Function name: Clear()
// * Clears the linked list of all its nodes. *
// **********************************************************
template<typename T>
void TList<T>::Clear()
{
	// Loop through entire list and delete all nodes
    while (!IsEmpty())
    {
        Node<T> * current = first;
        first = current->next;
        delete current;
        size--; // Decrement size each time we remove a node
    }
}

// **********************************************************
// * Function name: GetSize()
// * Returns the size of the linked list. *
// **********************************************************
template<typename T>
int TList<T>::GetSize() const
{
    return size;
}

// **********************************************************
// * Function name: InsertFront()
// * Creates a new node with input data d. *
// * Inserts the new node at the front of the linked list. *
// **********************************************************
template<typename T>
void TList<T>::InsertFront(const T &d)
{
	// Create our new node with the data that was passed in
    auto * newNode = new Node<T>(d);

    // If list is empty, this will be the only node in the list
    if (IsEmpty())
    {
        first = last = newNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        size++; // Increment size after insertion

        return;
    }

    // If list is not empty, insert the node at the front.
    first->prev = newNode;
    newNode->next = first;
    newNode->prev = nullptr;
    first = newNode; // Set the new node as the first in the list
    size++; // Increment size
}

// **********************************************************
// * Function name: InsertBack()
// * Creates a new node with input data d. *
// * Inserts the new node at the back of the linked list. *
// **********************************************************
template<typename T>
void TList<T>::InsertBack(const T &d)
{
	// Create the new node to be inserted using the data passed in
    auto * newNode = new Node<T>(d);

    // If the list is empty our new node will be the only node.
    if (IsEmpty())
    {
        first = last = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        size++;

        return;
    }

    // If list is not empty, insert the new node at the back of the list.
    newNode->next = nullptr;
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
    size++;
}

// **********************************************************
// * Function name: RemoveFront()
// * Removes the node at the front of the linked list. *
// **********************************************************
template<typename T>
void TList<T>::RemoveFront()
{
    // If the list is empty we don't need to do anything.
    if (IsEmpty())
    	return;

    // Create a temp node to hold the value of the first node
    Node<T> * temp = first;

    // If we are not at the end of the list, set the pointers accordingly
    if (first->next != nullptr)
    {
        first->next->prev = nullptr;
        first = first->next;
        delete temp;
        size--;
    }
    else
	{
    	// If we are at the end of the list, remove the front
        first = nullptr;
        size--;
    }
}

// **********************************************************
// * Function name: RemoveBack()
// * Removes the node at the back of the linked list. *
// **********************************************************
template<typename T>
void TList<T>::RemoveBack()
{
    // If the list is empty we don't need to do anything.
    if (IsEmpty())
    	return;

    // Create a temp node to hold the last element of the list
    Node<T> * temp = last;

    // If the last element is not the only element in the list, set the prev next pointers to null
    if (last->prev != nullptr)
    {
        last->prev->next = nullptr;
        last = last->prev; // Set the new last node
        delete temp;
        size--; // Decrement the size each time we remove a node
    }
    else
	{
    	// If the last node is the only node in the list, update first node to be null
        first = nullptr;
        size--;
    }
}

// **********************************************************
// * Function name: GetFirst()
// * Returns the first element of the linked list. *
// **********************************************************
template<typename T>
T& TList<T>::GetFirst() const
{
    if (IsEmpty())
    	return dummy;

    return first->data;
}

// **********************************************************
// * Function name: GetLast()
// * Returns the last element of the linked list. *
// * If the list is empty, the function return a dummy variable. *
// **********************************************************
template<typename T>
T& TList<T>::GetLast() const
{
    if (IsEmpty())
    	return dummy;

    return last->data;
}

// **********************************************************
// * Function name: GetIterator()
// * Returns an iterator to the front of the linked list. *
// **********************************************************
template<typename T>
TListIterator<T> TList<T>::GetIterator() const
{
    // If the list is empty we'll return a default iterator.
    if (IsEmpty())
        return TListIterator<T>();

    // If the list is not empty, we'll return an iterator pointing to the first element.
    TListIterator<T> iter;
    iter.ptr = first;

    return iter;
}

// **********************************************************
// * Function name: GetIteratorEnd()
// * Returns an iterator the the back of the linked list. *
// **********************************************************
template<typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const
{
    // If the list is empty, return a default iterator.
    if (IsEmpty())
        return TListIterator<T>();

    // If list is not empty, return iterator pointing to the last element.
    TListIterator<T> iter;
    iter.ptr = last;

    return iter;
}

// **********************************************************
// * Function name: Insert()
// * Creates a new node with input data d. *
// * Inserts the new node just before item at pos position. *
// **********************************************************
template<typename T>
void TList<T>::Insert(TListIterator<T> pos, const T &d)
{
	// Create a node and set it as the first element to iterate through the list
    Node<T> * current = first;

    // Iterate through the list to find the correct position for insertion
    while (current != nullptr)
    {
    	// If we arrive at the correct insertion position, we will insert the new node
        if (pos.ptr == current)
        {
            // Create the new node and insert it
            auto * newNode = new Node<T>(d);
            newNode->next = current;

            // If we are not at the beginning of the list, update the previous nodes pointers
            if (current->prev != nullptr)
            {
                newNode->prev = current->prev;
                current->prev->next = newNode;
            }
            else
			{
            	// If we are at the beginning of the list, update the prev pointer
                newNode->prev = nullptr;
                first = newNode; // Set it ad the first node in the list
            }

            // Update the prev pointer to point at the new node
            current->prev = newNode;
            size++;
        }

        // If we are at the end of the list, update the last element
        if (current->next == nullptr)
        	last = current;

        // If we are at the beginning of the list, update the first element
        if (current->prev == nullptr)
        	first = current;

        // Advance to the next node
        current = current->next;
    }
}

// **********************************************************
// * Function name: Remove()
// * Removes the node at position pos. *
// * Returns iterator to data the comes after the node being deleted. *
// **********************************************************
template<typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
	// If the list is empty, return the current position
    if (IsEmpty())
    	return pos;

    // Create the node that will be used to iterate through the list
    Node<T> * current = first;

    // Iterate through the entire list
    while(current != nullptr)
    {
    	// When we find the correct position for removal, remove the node
        if (current == pos.ptr)
        {
        	// If we are not at the beginning of the list or the end of the list
            if (current->prev != nullptr && current->next != nullptr)
            {
            	// Remove the node and update the neighbor nodes' pointers
                current->prev->next = current->next;
                current->next->prev = current->prev;
                size--; // Decrement size because we removed a node
            }
            // If we are at the end of the list, and not at the beginning of the list (list has more than one node)
            else if (current->next == nullptr && current->prev != nullptr)
            {
            	// Update the pointers to null since we're removing the last element
                current->prev->next = nullptr;
                size--;
            }
            // If we are at the beginning of the list and not the end of the list
            else if (current->prev == nullptr && current->next != nullptr)
            {
            	// Update the pointer to null
                current->next->prev = nullptr;
                size--;
            }
        }

        // If we are at the end of the list, update the last element of the list to current node
        if (current->next == nullptr)
        	last = current;

        // Advance to the next node
        current = current->next;
    }

    delete current;

    // Return iterator the the data after the one that was deleted
    return pos.Next();
}

// **********************************************************
// * Function name: Print()
// * Prints the list contents in order, separated by delimiter. *
// **********************************************************
template<typename T>
void TList<T>::Print(std::ostream &os, char delim) const
{
    if (IsEmpty())
    	return;

    Node<T> * current = first; // make a node for iterating through the list.

    // Iterate through the list and print each item
    while(current != nullptr)
    {
        cout << current->data << delim;
        current = current->next;
    }
}

// **********************************************************
// * Function name: TListIterator()
// * Default constructor for an iterator. *
// * Sets the iterator pointer to null. *
// **********************************************************
template<typename T>
TListIterator<T>::TListIterator()
{
    this->ptr = nullptr;
}

// **********************************************************
// * Function name: HasNext()
// * Returns true if there is a next item in the linked list. *
// **********************************************************
// Check if there is a next item in the linked list.
template<typename T>
bool TListIterator<T>::HasNext() const
{
	// Return true if there is a next item
    return this->ptr->next != nullptr;
}

// **********************************************************
// * Function name: HasPrevious()
// * Returns true if there is a previous item in the linked list.*
// **********************************************************
template<typename T>
bool TListIterator<T>::HasPrevious() const
{
	// Return true if there is a previous item
    return this->ptr->prev != nullptr;
}

// **********************************************************
// * Function name: Next()
// * Advanced the iterator to the next item in the linked list.*
// **********************************************************
template<typename T>
TListIterator<T> TListIterator<T>::Next()
{
    // If there is no next element, return a default iterator.
    if (HasNext())
        this->ptr = this->ptr->next;

    return *this;
}

// **********************************************************
// * Function name: Previous()
// * Returns an iterator to the previous item in the linked list.*
// **********************************************************
template<typename T>
TListIterator<T> TListIterator<T>::Previous()
{
    // If there is no previous node, return a default iterator.
    if (HasPrevious())
        this->ptr = this->ptr->prev;

    return *this;
}

// **********************************************************
// * Function name: GetData()
// * Returns the data element contained at the current node/ *
// **********************************************************
template<typename T>
T& TListIterator<T>::GetData() const
{
    return ptr->data;
}

// **********************************************************
// * Function name: operator+()
// * Overload of the operator +. *
// * Allows us to concatenate two lists using the + operator.*
// **********************************************************
template<typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2)
{
	// Create a new empty list to copy the contents into
    auto  newList = new TList<T>();

    // Get an iterator to the front of t1
    TListIterator<T> itr = t1.GetIterator();

    // Iterate through t1 and copy all nodes into the new list
    while (itr.HasNext())
    {
        newList->InsertBack(itr.GetData());
        itr.Next();

        // If we are at the end of the list, insert one more time
        if (!itr.HasNext())
        {
            newList->InsertBack(itr.GetData());
        }
    }

    // Get an iterator to the front of t2
    TListIterator<T> newItr = t2.GetIterator();

    // Iterate through t2 and copy all elements one by one to the back of the new list
    while(newItr.HasNext())
    {
        newList->InsertBack(newItr.GetData());
        newItr.Next();

        if (!newItr.HasNext())
        {
            newList->InsertBack(newItr.GetData());
        }
    }

    // Return our new concatenated list
    return *newList;
}
