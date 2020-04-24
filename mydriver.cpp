#include <iostream>
#include <string>

#include "tlist.h"

using namespace std;

template <typename T>
void PrintList(const TList<T>& L, string label)
{
    cout << label << " size is: " << L.GetSize() << "\n"
        << label << " = ";
    L.Print(cout);
    cout << "\n\n";
}

int main()
{
    // Testing an int type list
    TList<int> list1;

    // Adding elements to front and back of int list
    cout << "Adding some elements into a new list: \n" << endl;

    cout << "Inserting 7 at front..." << endl;
    list1.InsertFront(7);
	PrintList(list1, "list1");

	cout << "Inserting 10 at front..." << endl;
    list1.InsertFront(10);
	PrintList(list1, "list1");

	cout << "Inserting 0 at back..." << endl;
    list1.InsertBack(0);
	PrintList(list1, "list1");

	cout << "Inserting 0 at back..." << endl;
    list1.InsertBack(0);
	PrintList(list1, "list1");

	cout << "Inserting 25 at front..." << endl;
    list1.InsertFront(25);
	PrintList(list1, "list1");

	cout << "Inserting 1000 at back..." << endl;
    list1.InsertBack(1000);
	PrintList(list1, "list1");

	cout << "Inserting 100 at front..." << endl;
    list1.InsertFront(100);
	PrintList(list1, "list1");

	cout << "Inserting 50 at front..." << endl;
    list1.InsertFront(50);
	PrintList(list1, "list1");

	cout << "Inserting 200 at back..." << endl;
    list1.InsertBack(200);
	PrintList(list1, "list1");

	cout << "Inserting 407 at back..." << endl;
    list1.InsertBack(407);
    PrintList(list1, "list1");

    // Removing elements from front and back of int list
    cout << "Removing some elements:\n" << endl;

    cout << "Removing front..." << endl;
    list1.RemoveFront();
	PrintList(list1, "list1");

	cout << "Removing back..." << endl;
    list1.RemoveBack();
	PrintList(list1, "list1");

	cout << "Removing front..." << endl;
    list1.RemoveFront();
	PrintList(list1, "list1");

	cout << "Removing back..." << endl;
    list1.RemoveBack();
	PrintList(list1, "list1");

	cout << "Removing front..." << endl;
    list1.RemoveFront();
	PrintList(list1, "list1");

	cout << "Removing back..." << endl;
    list1.RemoveBack();
	PrintList(list1, "list1");

    // More insertion into int list
    cout << "Inserting some more elements:\n" << endl;

	cout << "Inserting 77 at front..." << endl;
    list1.InsertFront(77);
	PrintList(list1, "list1");

	cout << "Inserting 77 at back..." << endl;
    list1.InsertBack(77);
	PrintList(list1, "list1");

	cout << "Inserting 5000 at front..." << endl;
    list1.InsertFront(5000);
	PrintList(list1, "list1");

	cout << "Inserting 6666 at back..." << endl;
    list1.InsertBack(6666);
	PrintList(list1, "list1");

	cout << "Inserting 333 at front..." << endl;
    list1.InsertFront(333);
    PrintList(list1, "list1");

    // Testing RemoveFront to remove all elements in the int list
    cout << "Removing Front until list is empty:\n" << endl;
    while (!list1.IsEmpty())
    {
    	cout <<"Removing front..." << endl;
        list1.RemoveFront();
		PrintList(list1, "list1");
    }

    // Inserting more elements into the back of the int list
    cout << "Repopulating list1:\n" << endl;
    for (int i = 0; i < 10; i++)
    {
    	cout << "Inserting " << i << " at back..." << endl;
        list1.InsertBack(i);
		PrintList(list1, "list1");
    }

    // Testing RemoveBack to remove all elements of the int list
    cout << "Removing Back of list until the list is empty:\n" << endl;
    while (!list1.IsEmpty())
    {
    	cout << "Removing back of list..." << endl;
        list1.RemoveBack();
		PrintList(list1, "list1");
    }

    // Creating a char type list
    cout << "Populating a new char list:\n" << endl;
    TList<char> list2;

    // Insertion of characters
    cout << "Inserting C at front of list..." << endl;
    list2.InsertFront('C');
	PrintList(list2, "list2");

	cout << "Inserting R at back of list..." << endl;
    list2.InsertBack('R');
	PrintList(list2, "list2");

	cout << "Inserting T at back of list..." << endl;
    list2.InsertBack('T');
	PrintList(list2, "list2");

	cout << "Inserting L at back of list..." << endl;
    list2.InsertBack('L');
    PrintList(list2, "list2");

    // Testing front to back iterator insertion into char list
    cout << "Using a front-back iterator to insert characters:\n" << endl;
    TListIterator<char> itr = list2.GetIterator();
    itr.Next();

    cout << "Inserting H..." << endl;
    list2.Insert(itr, 'H');
	PrintList(list2, "list2");

    itr.Next();

	cout << "Inserting I..." << endl;
    list2.Insert(itr, 'I');
	PrintList(list2, "list2");

	cout << "Inserting S..." << endl;
    list2.Insert(itr, 'S');
	PrintList(list2, "list2");

    itr.Next();

	cout << "Inserting E..." << endl;
    list2.Insert(itr, 'E');
	PrintList(list2, "list2");

	cout << "Inserting L..." << endl;
    list2.Insert(itr, 'L');
	PrintList(list2, "list2");

	cout << "Inserting E..." << endl;
    list2.InsertBack('E');
    PrintList(list2, "list2");

    // Testing back to front iterator removal of elements in char list
    cout << "Using a back-front iterator to remove some characters:\n" << endl;
    TListIterator<char> it = list2.GetIteratorEnd();

	cout << "Removing..." << endl;
    list2.Remove(it);
	PrintList(list2, "list2");

    it.Previous();

	cout << "Removing..." << endl;
    list2.Remove(it);
	PrintList(list2, "list2");

    it.Previous();

	cout << "Removing..." << endl;
    list2.Remove(it);
	PrintList(list2, "list2");

    it.Previous();

	cout << "Removing..." << endl;
    list2.Remove(it);
	PrintList(list2, "list2");

    it.Previous();

	cout << "Removing..." << endl;
    list2.Remove(it);
	PrintList(list2, "list2");

    it.Previous();

	cout << "Removing..." << endl;
    list2.Remove(it);
	PrintList(list2, "list2");

    it.Previous();
    it.Previous(); // go back 2 spots

	cout << "Removing..." << endl;
    list2.Remove(it);
	PrintList(list2, "list2");

    it.Previous();

	cout << "Removing..." << endl;
    list2.Remove(it);
    PrintList(list2, "list2");

    // Adding elements to list
    cout << "Adding some more characters using InsertBack and InsertFront:\n" << endl;

	cout << "Inserting A at front..." << endl;
    list2.InsertFront('A');
	PrintList(list2, "list2");

	cout << "Inserting A at back..." << endl;
    list2.InsertBack('A');
	PrintList(list2, "list2");

	cout << "Inserting Z at back..." << endl;
    list2.InsertBack('Z');
	PrintList(list2, "list2");

	cout << "Inserting Z at back..." << endl;
    list2.InsertBack('Z');
	PrintList(list2, "list2");

	cout << "Inserting X at front..." << endl;
    list2.InsertFront('X');
    PrintList(list2, "list2");

    // Adding char elements using a front to back iterator
    cout << "Using iterator to add some more characters:\n" << endl;
    TListIterator<char> newItr = list2.GetIterator();

	cout << "Inserting Q..." << endl;
    list2.Insert(newItr, 'Q');
	PrintList(list2, "list2");

    newItr.Next();

	cout << "Inserting W..." << endl;
    list2.Insert(newItr, 'W');
	PrintList(list2, "list2");

	cout << "Inserting S..." << endl;
    list2.Insert(newItr, 'S');
	PrintList(list2, "list2");

    newItr.Previous();

	cout << "Inserting S..." << endl;
    list2.Insert(newItr, 'S');
	PrintList(list2, "list2");

    newItr.Previous();
    newItr.Previous(); // go back 2 spots

	cout << "Inserting S..." << endl;
    list2.Insert(newItr, 'S');
	PrintList(list2, "list2");

    newItr.Next();

	cout << "Inserting S..." << endl;
    list2.Insert(newItr, 'S');
	PrintList(list2, "list2");

    newItr.Next();
    newItr.Next();
    newItr.Next();
    newItr.Next(); // advance 4 spots

	cout << "Inserting D..." << endl;
    list2.Insert(newItr,'D');
    PrintList(list2, "list2");

    // Populate a new int type list
    cout << "Creating a new int list:\n" << endl;
    TList<int> list3;

    for (int i = 0; i < 10; i++)
    {
    	cout << "Inserting 0 at back..." << endl;
        list3.InsertBack(0);
		PrintList(list3, "list3");
    }

    // Populate another new int type list
    cout << "Creating another new int list:\n" << endl;
    TList<int> list4;

    for (int i = 0; i < 10; i++)
    {
		cout << "Inserting 7 at front..." << endl;
        list4.InsertFront(7);
		PrintList(list4, "list4");
    }

    // Testing the overloaded + operator to concatenate lists
    cout << "Concatenate list3 and list4:\n" << endl;
    TList<int> list5 = list3 + list4;

    PrintList(list5, "list5");

    // Populate another new char list
    cout << "Creating another char list:\n" << endl;
    TList<char> list6;

    for (int i = 0; i < 10; i++)
    {
    	cout << "Inserting C at back..." << endl;
        list6.InsertBack('C');
		PrintList(list6, "list6");
    }

    // Populate another new char list
    cout << "Creating one last char list:\n" << endl;
    TList<char> list7;

    for (int i = 0; i < 10; i++)
    {
    	cout << "Inserting N at front..." << endl;
        list7.InsertFront('N');
		PrintList(list7, "list7");
    }

    // Testing concatenation of lists
    cout << "Concatenate list6 and list7:\n" << endl;
    TList<char> list8;
    list8 = list6 + list7;

    PrintList(list8, "list8");

    // Testing removal of all elements using a back to front iterator
    cout << "Removing all elements from list8 using a back-front iterator:\n" << endl;
    TListIterator<char> iter = list8.GetIteratorEnd();

    while (!list8.IsEmpty())
    {
        list8.Remove(iter);
    }

    PrintList(list8, "list8");

    // Testing removal of all elements using a front to back iterator
    cout << "Removing all elements from list7 using a front-back iterator: " << endl;
    TListIterator<char> itt = list7.GetIterator();
    while (!list7.IsEmpty())
    {
        list7.Remove(itt);
    }

    PrintList(list7, "list7");
}
