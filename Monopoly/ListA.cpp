#include "ListA.h"
#include <iostream>

using namespace std;

listClass::listClass()
// constructor
// Precondition: none
// Postcondition: object created
{
	Size = 0;
}

listClass::listClass(listClass& L)
// copy constructor
// Precondition: none
// Postcondition: listClass copied
{
	bool Success;
	for(int i=0; i < L.ListLength(); i++)
	{
		ListRetrieve(i, L.Items[i], Success);
		ListInsert(i,L.Items[i], Success);
	}
}

listClass::~listClass()
// destructor
// Precondition: The constructor has been called
// Postcondition: The object is destroyed
{
}

bool listClass::ListIsEmpty()
// Preconditions: The constructor has been called
// Postconditions: Returns TRUE if the list is empty, otherwise returns FALSE
{
	return (Size == 0);
}

int listClass::ListLength()
// Determaines the length of the list.
// Preconditions: The constructor has been called.
// Postconditions: Returns the number of items that are currently in the list.
{
	return Size;
}

void listClass::ListInsert(int NewPosition, listItemType NewItem, bool& Success)
// Inserts an item into the list.
// Precondition: The constructor has been called. NewPosition indicates where the 
// insertion should occur, NewItem is the item to be inserted.
// Postcondition: If insertion is successful, NewItem is at position NewPosition in
// the list, other items are renumbered accordingly, and Success is TRUE; otherwise
// Success is FALSE.
// Note: Insertion will not be successful if NewPosition is < 1 or > ListLength()+1.
{
	if(Size > MAX_LIST)
		Success = false;
	else
	{
		Size = NewPosition;
		Items[Size] = NewItem;
		Size++;
		Success = true;
	}
}

void listClass::ListDelete(int Position, bool& Success)
// Deletes an item from a list.
// Precondition: The constructor has been called. Position indicates where the deletion
// should occur.
// Postcondition: If 1 <= Position <= ListLength(), the item at position Position in the
// List is deleted, other items are renumbered accordingly, and Success is TRUE;
// otherwise Success is FALSE.
{
	if(Size <= 0)
		Success = false;
	else
	{
		Size--;
		Success = true;
	}
}

void listClass::ListRetrieve(int Position, listItemType& DataItem, bool& Success)
// Retrieves a list item by position number.
// Precondition: The constructor has been called.
// Position is the number of the item to be retrieved.
// Postcondition: If 1 <= Position <= ListLength(), DataItem is the value of the desired
// item and Success is TRUE; otherwise Success is FALSE.
{
	if(1 <= Position && Position <= ListLength())
	{
		DataItem = Items[Index(Position)];
		Success = true;
	}
	else
		Success = false;
}

int listClass::Index(int Position)
// Converts the position of an item in a list to the correct index within
// Its array representation.
{
	return Position-1;
}
