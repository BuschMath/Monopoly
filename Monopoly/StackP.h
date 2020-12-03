#ifndef STACKP_H
#define STACKP_H
// ***********************************************************
// David Busch
// C++ Data Structures
// Due Date Feb. 25, 2005
// Header file StackP.h for the ADT list.
// Pointer-based implementation of a Stack
// This header file was created by John Hansen
// ***********************************************************

#include "Cards.h"

typedef Card StackItemType;
struct StackNode;
typedef StackNode* ptrType;		// pointer to node

class StackClass
{
public:
	// Constructors and destructors.
	StackClass();				// default constructor
	~StackClass();				// destructor

	// list operations
	bool IsEmpty();
	// Preconditions: The constructor has been called.
	// Postconditions: Returns true if the stack is empty, otherwise returns false.

	bool IsFull();
	// Preconditions: The constructor has been called.
	// Postconditions: Returns false if the there is no free memory available.

	void Push(StackItemType item);	// Inserts an item onto the stack.
	// Precondition: The constructor has been called, item is the item to be inserted. Must check
	// IsFull() prior to pushing an item onto the stack.
	// Postcondition: The item has been added to the stack.

	void Pop(StackItemType& item);	// Removes an item from the stack.
	// Precondition: The constructor has been called. Must check IsEmpty() prior to popping an
	// item from the stack.
	// Postcondition: The top item on the stack is removed and returned in item.

	void MakeEmpty();	// Empties the stack.
	// Precondition: The constructor has been called.
	// Postcondition: The top pointer points to NULL and the nodes have been deleted.

private:
	ptrType topPtr;
};	// end class
// End of header file.
#endif // !STACKP_H