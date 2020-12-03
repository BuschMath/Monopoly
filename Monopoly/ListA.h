#ifndef LISTA_H
#define	LISTA_H
// *****************************************************************
// Header file ListA.h for the ADT list.
// Array-based implementation.
// *****************************************************************

#include "Cards.h"

const int MAX_LIST = 100;
typedef Card listItemType;


class listClass

{
public:
// Constructors anddestructors.
	listClass();				// constructor
	listClass(listClass& L);	// copy constructor
	~listClass();				// destructor

// list operations
	bool ListIsEmpty();
	// Preconditions: The construcotr has been called.
	// Postconditions: Returns TRUE if the list is empty, otherwise returns FALSE.

	int ListLength();
	// Determines the length of the list.
	// Preconditions: The constructor has been called.
	// Postconditions: Returns the number of items that are currently in the list.

	void ListInsert(int NewPosition, listItemType NewItem, bool& Success);
	// Inserts an item into the list.
	// Precondition: The constructor has been called. NewPosition indicates where the
	// insertion should occur, NewItem is the item to be inserted.
	// Postcondition: If insertion is successful, NewItem is at position NewPostion in
	// the list, other items are renumbered accordingly, and Success is TRUE; otherwise
	// Success is FALSE.
	// Note: Insertion will not be successful if NewPositon is < 1 or > ListLength()+1.

	void ListDelete(int Postion, bool& Success);
	// Deletes an item from a list.
	// Precondition: The constructor has been called. Postion indicates where the deletion
	// should occur.
	// Postcondition: If 1 <= Position <= ListLength(), the item at position Position in the
	// list is deleted, other items are renumbered accordingly, and Success is TRUE;
	// otherwise Success is FALSE.

	void ListRetrieve(int Position, listItemType& DataItem, bool& Success);
	// Retrieves a list item by position number.
	// Precondition: The constructor has been called.
	// Postion is the number of the item to be retrieved.
	// Postcondition: If 1 <= Position <= ListLength(), DataItem is the value of the desired
	// item and Success is TRUE; otherwise Success is FALSE.


private:
	listItemType Items[MAX_LIST];		//array of list items
	int Size;							// number of items on list

	int Index(int Position);
	// Converts the position of an item in a list to the correct index within
	// its array representation.
};	// end class
// End of header file.
#endif // !LISTA_H