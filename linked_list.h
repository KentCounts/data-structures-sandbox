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

	bool isEmpty() const;

	void clear();

	void PushFront(int value);
	void PushBack(int value);

	void PopFront();
	void PopBack();

private:
	Node* head;
	std::size_t size;

};