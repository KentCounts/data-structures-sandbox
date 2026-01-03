#include "linked_list.h"

// node
Node::Node(int value, Node* next)
	: value(value), next(next)
{
}

// list constructor
LinkedList::LinkedList()
	: head(nullptr), size(0)
{
}

// list destructor
LinkedList::~LinkedList()
{

	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}


// init function
// define head
// define size

// is empty?
// head null

// push front
// new node
// new head
// link new head to old head
// size +1

// push back
// new node
// no next
// if else for head
// define next 
// size +1

// pop front
// if empty
// remove head
// new head = next
// size -1

// pop back
// if empty
// if singular
// remove last
// size -1



// other ideas

// search
// insert
// remove
// clear
// size
// traverse
// deep copy?