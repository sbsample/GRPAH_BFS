
//Staunton Sample
//sbsample
//pa2
//Lex.c

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "List.h"



// Constructors
typedef struct NodeObj
{
	int value;
	struct NodeObj* next;
	struct NodeObj* previous;

}NodeObj;

typedef NodeObj* Node;

typedef struct ListObj
{
	Node front;
	Node back;
	Node index;
	int cursor;
	int length;
}ListObj;

List newList()
{
	List L = malloc(sizeof(ListObj));
	L -> front = NULL;
	L -> back = NULL;
	L -> cursor = -1;
	L -> index = NULL;
	L -> length = 0;

	return(L);
}
//freeList()
// frees memory in list by eliminating all nodes
void freeList(List* pl)
{
	if (pl != NULL && *pl != NULL)
	{
		while (length(*pl) >0)
		{
			deleteFront(*pl);
		}
		free(*pl);
		*pl =NULL;
	}
}
//newNode()
//  creates new node
Node newNode(int data)
{
	Node node = malloc(sizeof(NodeObj));
	node -> value = data;
	node -> next = NULL;
	node -> previous = NULL;

	return node;
}
// length()
// returns length of list
int length(List L)
{
	return L -> length;
}
// index()
// returns index of list
int index(List L)
{
	return L -> cursor;
}
//front()
// returns node front of list
int front(List L)
{

	return L -> front -> value;

}
// back()
//returns node at back of list
int back(List L)
{
	return L -> back -> value;
}
//get()
//returns node at cursor
int get(List L)
{
	printf("This is get L -> index : %d\n",L -> index -> value);
	return L -> index -> value;
}
// equals()
//does List A equal List B
int equals(List A, List B)
{
	Node aFind = A -> front;
	Node bFind = B -> front;

	if (A -> length == 0 ||   B -> length == 0)
	{
		return 0;
	}
	else if (A -> length != B -> length )
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < A -> length; i++)
		{
			if (aFind -> value != bFind -> value)
			{
				return 0;
			}
			else
			{
				aFind = (Node) aFind -> next;
				bFind = (Node) bFind -> next;
			}
		}
	}
	return 1;
}
// clear()
// clears out list
void clear(List L)
{
	if(L -> index != NULL)
		{
			L -> index = NULL;
		}
	if(L -> back != NULL)
		{
			L -> back = NULL;
		}
	for (int i = 0; i < L-> length; i++)
	{
		if (L -> length > 0)
		{
			Node temp = L -> front;
			L -> front = temp -> next;
			L -> front -> previous = NULL;
			temp -> next = NULL;
			free(temp);


		}

		L -> cursor = -1;
		L -> length = 0;

	}
}
//moveFront()
// moves the cursor to the back of the list
void moveFront(List L)
{
	if (length > 0)
	{
		L -> cursor = 0;
		L -> index = L -> front;

	}
}
// moveBack()
//moves cursor to back of the list
void moveBack(List L)
{
	if (L -> length >0)
	{
		L -> cursor = L -> length -1;
		L -> index =  L -> back;
	}
}
// movePrev()
// moves cursor back one
void movePrev(List L)
{
	if (L -> cursor > 0)
	{
		L -> cursor -= 1;
		L -> index = L -> index -> previous;
	}
	else if ( L -> cursor == 0)
	{
		L -> cursor = -1;
		L -> index = NULL;
	}
}
//moveNext()
// moves cursor next
void moveNext(List L)
{
	if (L -> cursor >= 0 && L -> cursor != L -> length - 1)
	{
		L -> cursor += 1;
		L -> index = L -> index -> next;
	}
	else if (L -> cursor == L -> length - 1)
	{
		L -> cursor = -1;
		L -> index = NULL;
	}
}
// prepend()
// adds element to the front of list
void prepend(List L, int data)
{
	Node n = newNode(data);
	if (length(L) == 0)
	{
		L -> front = n;
		L -> back = n;
	}
	else
	{
		L -> front -> previous = n;
		n -> next = L -> front;
		L -> front = n;
		if (L -> cursor >= 0)
		{
			L -> cursor += 1;
		}
	}
	L -> length += 1;

}
// append()
// adds node to back of list
void append(List L, int data)
{
	Node n = newNode(data);
	if ( L ->length == 0)
	{
		L -> front = n;
		L -> back = n;
	}
	else
	{
		n -> previous = L -> back;
		L -> back -> next = n;
		L -> back = n;
	}

	L -> length += 1;
}
//insertBefore()
// inserts before cursor
void insertBefore(List L, int data)
{
	Node n = newNode(data);
	if (L -> cursor > 0)
	{
		n -> next = L -> index;
		L -> index -> previous -> next = n;
		n -> previous = L -> index -> previous;
		L ->index -> previous = n;
		L -> length += 1;
		L -> cursor += 1;
	}
	else if (L -> cursor == 0)
	{
		n -> next = L -> index;
		L -> index -> previous = n;
		L -> front = n;
		L -> length += 1;
		L -> cursor += 1;
	}
}

//insertAfter()
//inserts node after cursor
void insertAfter(List L, int data)
{
	Node n = newNode(data);
	if (L -> cursor < L -> length - 1 && L -> cursor != -1)
	{

		n -> previous = L -> index;
		n -> next = L -> index -> next;
		L -> index -> next -> previous = n;
		L -> index -> next = n;
		L -> length += 1;
	}
	else if (L -> cursor ==L -> length -1)
	{
		n -> previous = L -> index;
		L -> index -> next = n;
		L -> length += 1;
		L -> back = n;
	}

}

//deleteFront()
// deletes node at front of list
void deleteFront(List L)
{
	Node temp = L -> front;
	if (L -> length > 1 && L -> cursor == -1)
	{

		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		L -> length -= 1;

	}
	else if (L -> length > 1 && L -> cursor != 0)
	{

		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		L -> length -= 1;
		L -> cursor -= 1;

	}

	else if (L -> length > 1 && L -> cursor == 0)
	{

		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		L -> length -= 1;
		L -> cursor = -1;
		L -> index = NULL;
	}
	else if	(L -> length == 1 && L -> cursor == 0)
	{
		L -> front = NULL;
		L -> back = NULL;
		L -> cursor = -1;
		L -> index = NULL;
		L -> length = 0;
	}


	else if (L -> length == 1 && L -> cursor == -1)
	{

		L -> front = L -> front -> next;
		L -> length = 0;

	}
	if(temp != NULL)
  	{
  		free(temp);
  	}
	temp = NULL;

}
//deleteBack()
//deletes back of the list
void deleteBack(List L)
{

	if (L -> length > 1 && L -> cursor < L -> length - 1)
	{
		L -> back = L -> back -> previous;
		L -> back -> next = NULL;
		L -> length -= 1;

	}
	else if (L -> length == 1 && L -> cursor == 0)
	{
		L -> front = NULL;
		L -> back = NULL;
		L -> cursor = -1;
		L -> index = NULL;
		L -> length = 0;
	}
	else if(L -> length > 1 && L -> cursor == L -> length - 1)
	{
		L -> back = L -> back -> previous;
		L -> cursor = -1;
		L -> index = NULL;
		L -> length -= 1;
	}
	else if (L -> length == 1 && L -> cursor == -1)
	{
		L -> front = NULL;
		L -> back = NULL;
		L -> length = 0;

	}

}
//delete()
//deletes at cursor
void delete(List L)
{
	Node temp;
	if (L -> index == L -> front)
	{
		temp = L -> front;
		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		temp -> next = NULL;
		L -> index = NULL;
		L -> cursor = -1;

	}
	else if (L -> index == L -> back)
	{
		temp = L -> back;
		L -> back = L -> back -> previous;
		L -> back -> next = NULL;
		temp -> previous = NULL;
		L -> index = NULL;
		L -> cursor = -1;
	}
	else
	{
		L -> index -> previous -> next = L -> index -> next;
		L -> index -> next -> previous = L -> index -> previous;
		L -> index -> next = NULL;
		L -> index -> previous = NULL;
		temp = L -> index;
		L -> index = NULL;
		L -> cursor = -1;
  	}

  	if(temp != NULL)
  	{
  		free(temp);
  	}
  	L -> length -= 1;
	temp = NULL;
}
// copyList()
// copies the list into new list
List copyList(List L)
{
	List newL = newList();

	Node tempNode = L -> front;
	while (tempNode != NULL)
	{
		append(newL, tempNode -> value);
		tempNode = tempNode-> next;
	}

	return newL;
}
//printList
// prints list
void printList(FILE* out, List L)
{
	Node n = L -> front;
	for (int i = 0; i < L -> length - 1; i++)
	{
		 fprintf(out,"%d ", n -> value);
	}

}

