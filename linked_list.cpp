#include "linked_list.h"
#include <iostream>

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
// builds basic filled list for testing
void LinkedList::init()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    size = 0;

    // Build list: 1 2 3 4 5 
    for (int i = 5; i >= 1; --i)
    {
        head = new Node(i, head);
        ++size;
    }
}

// print list
void LinkedList::print() const
{
    Node* current = head;

    std::cout << "List contents: ";

    while (current != nullptr)
    {
        std::cout << current->value;

        if (current->next != nullptr)
        {
            std::cout << " > ";
        }

        current = current->next;
    }

    std::cout << std::endl;
}

// is empty?
// head null
bool LinkedList::isEmpty() const
{
    return head == nullptr; 
}

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