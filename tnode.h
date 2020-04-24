#ifndef ASSIGNMENT1_TNODE_H
#define ASSIGNMENT1_TNODE_H

#endif //ASSIGNMENT1_TNODE_H

#include <utility>

template <typename T>	class TList;		// forward declaration
template <typename T>	class TListIterator;	// forward declaration

template <typename T>
class Node
{
    friend class TList<T>;
    friend class TListIterator<T>;
public:
    Node(const T& d);
    Node(T && d);

private:
    T data;		// data element to store of type T
    Node<T> * prev;	// pointer to previous node
    Node<T> * next;	// pointer to next node
};

template <typename T>
Node<T>::Node(const T& d)

{
    data = d;				// set data
    prev = next = nullptr;		// null pointers to start
}

template <typename T>
Node<T>::Node(T && d)

{
    data = std::move(d);			// set data
    prev = next = nullptr;		// null pointers to start
}
