// ***********************************************************
// David Busch
// C++ Data Structures
// Due Date Feb. 25, 2005
// Implementation file StackP.cpp for the ADT list.
// Pointer-based implementation of a Stack
// 
// ***********************************************************

#include "StackP.h"
#include <cstddef>
#include <iostream>

using namespace std;

struct StackNode			// Node consisting of a pointer and a int. data type.
{
	StackItemType Item;		// Int. data storage location
	ptrType Next;			// Pointer.
};

StackClass::StackClass()
// Default constructor
// Precondition: none
// Postcondition: Object created
{
	topPtr = NULL;
}

StackClass::~StackClass()
// Destructor
// Precondition: The constructor has been called.
// Postcondition: Object destroyed
{
	StackNode* tempPtr;

	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr ->Next;
		delete tempPtr;
	}

}

bool StackClass::IsEmpty()
// Precondition: The constructor has been called.
// Postconditions: Returns true if the stack is empty, otherwise returns false.
{
	return(topPtr == NULL);
}

bool StackClass::IsFull()
// Preconditions: The constructor has been called.
// Postconditions: Returns false if the there is no free memory available.
{
	StackNode* location;
	try
	{
		location = new StackNode;
		delete location;
		return true;
		
	}
	catch(std::bad_alloc exception)
	{
		return false;
	}
}

void StackClass::Push(StackItemType item)
// Inserts an item onto the stack.
// Precondition: The constructor has been called, item is the item to be inserted. Must check
// IsFull() prior to pushing an item onto the stack.
// Postcondition: The item has been added to the stack.
{
	if(IsFull())
	{

		ptrType tempptr = new StackNode;
		tempptr ->Item = item;
		tempptr ->Next = topPtr;
		topPtr = tempptr;
	}
}

void StackClass::Pop(StackItemType& item)
// Removes an item from the stack.
// Precondition: The constructor has been called. Must check IsEmpty() prior to popping an
// item from the stack.
// Postcondition: The top item on the stack is removed and returned in item.
{
	if(IsEmpty() == false)
	{
		StackNode* tempPtr;
		tempPtr = topPtr;
		item = topPtr -> Item;
		topPtr = topPtr ->Next;
		delete tempPtr;
	}
}

void StackClass::MakeEmpty()
// Empties the stack.
// Precondition: The constructor has been called.
// Postcondition: The top pointer points to NULL and the nodes have been deleted.
{
	StackNode* tempPtr;

	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr ->Next;
		delete tempPtr;
	}
}
