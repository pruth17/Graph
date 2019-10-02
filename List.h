/**

 * Pruthvi Punwar



 */



#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <assert.h>
#include <iomanip>
#include <string>
#include <cstddef> //for NULL
using namespace std;

template <class listdata>
class List
{

private:
    struct Node
	{
        listdata data;
        Node* next;
        Node* prev;


        Node(listdata newData)
        {
            data = newData;
            next = NULL;
            prev = NULL;

        }
    };
    Node* first;
    Node* last;
    Node* iterator;
    int length;

    void reversePrint(Node* node) const;
    //Helper function for the public reversePrint() function.
    //Recursively prints the data in a List in reverse.

    bool isSorted(Node* node) const;
    //Helper function for the public isSorted() function.
    //Recursively determines whether a list is sorted in ascending order.

    int binarySearch(int low, int high, listdata data) const;
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List
    //Post: The iterator location has not been changed


public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: To Check if we have any data in the List.

    List(const List &list);
    // Copy Constructor.

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition:  Checks if the memory is free or not.

    /**Accessors*/

    listdata getFirst() const;
    //Returns the first data in the list
    //Precondition: If the first data is empty or not.

    listdata getLast() const;
    //Returns the last data in the list
    //Precondition: If the last data is empty or not.

    listdata getIterator();

    bool isEmpty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list

    /**Manipulation Procedures*/

    void removeFirst();
    //Removes the value stored in first node in the list
    //Precondition: Checks if there is a value stored in the first node in the list.
    //Postcondition: Removes the first value from the list.


    void removeLast();
    //Removes the value stored in the last node in the list
    //Precondition:  Checks if the list is empty or not.
    //Postcondition: Removes last value from list.

    void insertFirst (listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Check if the value is added at the beginning of the list.

    void insertLast(listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Check if the value is added at the end of the list.

    /**Additional List Operations*/

    void printList(ostream &out) const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..

    void printNumberedList();
    //Prints the value of each data in list, numbered and sepreated by a new line.

    void startIterator();
    //Points the Iterator to the first element in the List;
    //Pre: List should not be empty.

    void removeIterator();
    //Removes the data from the List, which iterator was pointing at.
    //Pre:List should not be empty.

    void insertIterator(listdata data);
    // Inserts a data in the list after the value at which the
    // iterator was pointing.
    // Pre: iterator!=NULL

    void advanceIterator();
    // Moves the iterator ahead in the list by one position.

    void reverseIterator();
    // Moves the iterator behind in the list by one positon.

    bool operator==(const List& list);
    // Returns whether the two list are equal or not.

    bool offEnd() const;
    // Returns whether the iterator is NULL or not.

    void reversePrint() const;
           //Wrapper function that calls the reverse helper function to print a list in reverse
           //prints nothing if the List is empty

    bool isSorted() const;
    //Wrapper function that calls the isSorted helper function to determine whether
   //a list is sorted in ascending order.
   //We will consider that a list is trivially sorted if it is empty.
   //Therefore, no precondition is needed for this function

    int getIndex() const;
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered starting at 1 through the size of the list
    //Pre: !offEnd()

    void advanceToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
    //Nodes are numbered starting at 1 through the size of the List
    //Pre: size != 0
    //Pre: index <= size

    int linearSearch(listdata data) const;
    //Searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Does not call the indexing functions in the implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0
    //Post: The iterator location has not been changed

    int binarySearch(listdata data) const;
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)
    //Post: The iterator location has not been changed
};



template <class listdata>
List<listdata>::List()
{
    first = NULL;
    last = NULL;
    iterator = NULL;
    length = 0;
}
template <class listdata>
List<listdata>::List(const List &list)

{

	 if(list.first == NULL) //If the original list is empty, make an empty list for this list
	    {
	        first = last = iterator = NULL;
	    }
	    else
	    {
	        first = new Node(list.first->data); //calling Node constructor
	        Node* temp = list.first; //set a temporary node pointer to point at the first of the original list
	        iterator = first; //set iterator to point to first node of the new list

	        while(temp->next != NULL)
	        {

           temp = temp->next; //advance up to the next node in the original list
	            iterator->next = new Node(temp->data); //using node constructor to create new node w/ copy of data
                iterator->next->prev=iterator;
	            iterator = iterator->next; //advance to this new node
	            //iterator->prev = temp;
	           // temp = temp->next; //advance up to the next node in the original list

	        }

	        last = iterator; //Why do I need this line of code?
	        iterator = NULL;

	    }

	    length = list.length;
}
template <class listdata>
List<listdata>::~List()
{
    Node* b = first;
    Node* a = NULL; //a stands for "after" (i.e. after b)
    while (b != NULL)
    {
        a = b->next; //move a to node after b
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}
template <class listdata>
void List<listdata>::printList(ostream& out) const
{
  
    Node* temp = first; //create a temporary iterator
    while (temp != NULL)
    {
        out << temp->data << " " ;
        temp = temp->next;
        //Add two lines of code here

        //Hint: One statement should contain a cout

    }
    //cout << endl; //What does this do?

}

template<class listdata>
listdata List<listdata>::getIterator()
{
    assert(iterator!=NULL);
    return iterator->data;

}

template <class listdata>
void List<listdata>::printNumberedList()
{
    assert(length!=0);
    int n=1;
    Node* temp=first;
    cout << endl;
    while(temp!=NULL)
    {
        cout << endl;
        cout << n<< "). "<< temp->data << "  " ;

        temp=temp->next;
        n++;



    }


}


template <class listdata>
void List<listdata>::insertFirst(listdata data)
{
    Node* N = new Node(data);
    if (length == 0)
    {
        first = N;
        last = N;

    }
    else
    {
        N->next = first;
        first->prev=N;
        first = N;
    }
    length++;
}
template <class listdata>
void List<listdata>::insertLast(listdata data)
{

    Node* N = new Node(data);
    if (length == 0)
    {
        first = N;
        last = N;
    }
    else
    {

        N->prev=last;
        last->next = N;
        last = N;
    }
    length++;
}

template <class listdata>
void List<listdata>::removeFirst()
{
    assert(length!=0);

    if(length == 1)
    {
        delete first;
        first = last = NULL;
        length = 0;
    }
    else
    {
        Node* temp = first;
        first = first->next;
        first->prev=NULL;
        delete temp;
        length--;
    }
}

template <class listdata>
void List<listdata>::removeLast()
{
    assert(length!=0);
    //fill in the line here

    if (length==1)
    {
        delete last;
        first = last = NULL;
        length = 0;

        //fill in the missing lines here

    }


    else
    {
        Node *temp=last;
        last = last->prev;
        delete temp;
        last->next = NULL;
        length--;
    }


}

template <class listdata>
bool List<listdata>::isEmpty() const
{
    return length == 0;
}

template <class listdata>
bool List<listdata>::offEnd() const
{
    return iterator == NULL;
}

template <class listdata>
int List<listdata>::getLength() const
{
    return length;
}

template <class listdata>
void List<listdata>::startIterator()
{
	assert(length != 0);
    iterator = first;
}

template <class listdata>
listdata List<listdata>::getFirst() const
{
    assert(first!=NULL);
    return first -> data;

}


template <class listdata>
listdata List<listdata>::getLast() const
{
    assert(last!=NULL);
    return last->data;
}

template <class listdata>
void List<listdata>::removeIterator()
{
    assert(iterator!=NULL);
    assert(length!=0);
    if(iterator==first)
    {
        removeFirst();

    } else if(iterator==last)
    {
    	removeLast();
    }

    else
    {
        iterator->prev->next=iterator->next;
        iterator->next->prev=iterator->prev;
        delete iterator;
        iterator=NULL;
        length--;
    }

}

template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
	assert(iterator!=NULL);

  if(iterator==last)
    {
        insertLast(data);
    }
    else
    {

        Node* N = new Node(data);
        N->next=iterator->next;
        N->prev = iterator;
        iterator->next=N;
        iterator->next->prev=N;
        length++;
    }


}

template <class listdata>
void List<listdata>::advanceIterator()
{
	assert(iterator!=NULL);
    iterator=iterator->next;
}

template <class listdata>
void List<listdata>::reverseIterator()
{
	assert(iterator!=NULL);
    iterator=iterator->prev;
}

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    Node* temp1 = first;
    Node* temp2 = list.first;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template <class listdata>
void List<listdata>::reversePrint(Node* node) const
{
	if(node==NULL)
	{
		return ;
	}

	else
	{
		cout << node->data << " ";
		reversePrint(node->prev);
	}
}

template <class listdata>
void List<listdata>::reversePrint() const
{
	if(isEmpty())
	{

		cout << endl;
	}
	else
	{
		reversePrint(last);
	}
}

template <class listdata>
bool List<listdata>::isSorted(Node* node) const
{
	if(node == last)
	{
		return true;
	}

	else if(node->data <= node->next->data)
	{
		return isSorted(node->next);
	}

	else
	{

		return false;
	}
}

template <class listdata>
bool List<listdata>::isSorted() const
{
	if(isEmpty())
	{
		cout << endl;
		return true;
	}
	else
	{
		return isSorted(first);
	}
}

template <class listdata>
int List<listdata>::getIndex() const
{
	assert(!offEnd());
	Node* temp = first;
	int l=1;
	while(temp != iterator)
	{
		temp=temp->next;
		l++;
	}
	return l;
}

template <class listdata>
void List<listdata>::advanceToIndex(int index)
{
	assert(length!=0);
	assert(index <= length);
	startIterator();
	for(int i=1; i < index; i++)
	{
		advanceIterator();
	}
}

template <class listdata>
int List<listdata>::linearSearch(listdata data) const
{
   // assert(length != 0);
    Node* temp = first;
    int p=1;
    while(temp != NULL)
    {
        if(temp->data == data)
            return p;
        else
        {
            p++;
            temp = temp->next;
        }
    }
    return -1;
}

template<class listdata>
int List<listdata>::binarySearch(listdata data) const
{
    return binarySearch(1, length, data);
}

template<class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data) const
{
    assert(isSorted());
    assert(length!=0);
    Node* midpoint = first;
    if(high < low)
        return -1;
    int mid = low + (high-low)/2;
    for(int i = 0; i < mid; i++)
    {
        midpoint=midpoint->next;
    }
    if(midpoint->data == data)
    {
        return mid+1;
    }
    else if (data < midpoint->data)
        return binarySearch(low , mid-1, data);
    else
        return binarySearch(mid+1, high , data);
}

#endif /* LIST_H_ */

