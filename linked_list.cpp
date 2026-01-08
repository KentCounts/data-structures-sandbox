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
    clear();
}


// init function
// define head
// define size
// builds basic filled list for testing
void LinkedList::init()
{
    clear();

    // Build list: 1 2 3 4 5 
    for (int i = 5; i >= 1; --i)
    {
        PushBack(i);
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

// clear
void LinkedList::clear()
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
}

// push front
// new node
// new head
// link new head to old head
// size +1
void LinkedList::PushFront(int value)
{
    Node* newNode = new Node(value, head);
    head = newNode;
    size++;
}


// push back
// new node
// no next
// if else for head
// define next 
// size +1
void LinkedList::PushBack(int value)
{
    Node* newNode = new Node(value, nullptr);

    if (head == nullptr)
    {
        head = newNode;
    }

    else
    {
        Node* current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    size++;
}


// pop front
// if empty
// remove head
// new head = next
// size -1
void LinkedList::PopFront()
{
    if (head == nullptr)
    {
        std::cout << "List is empty. Cannot pop front.\n";
        return;
    }

    Node* removed = head;
    head = head->next;
    delete removed;
    size--;

    std::cout << "Front element removed.\n";
}

// pop back
// if empty
// if singular
// remove last
// size -1
void LinkedList::PopBack()
{
    if (head == nullptr)
    {
        std::cout << "List is empty. Cannot pop back.\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* current = head;
        Node* prev = nullptr;

        while (current->next != nullptr)
        {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        delete current;
    }

    size--;
    std::cout << "Back element removed.\n";
}




// other ideas

// search
// insert
// remove
// size
// traverse
// deep copy?