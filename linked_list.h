#pragma once

#include <cstddef>

struct Node
{
	int value;
	Node* next;

	// constructor
	Node(int value, Node* next = nullptr);

};

class LinkedList
{
public:

	// constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// disable shallow copy
	LinkedList(const LinkedList&) = delete;
	LinkedList& operator=(const LinkedList&) = delete;

	void print() const;

	void init();

private:
	Node* head;
	std::size_t size;

};