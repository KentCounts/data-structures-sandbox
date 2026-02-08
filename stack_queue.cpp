// stack 
// stack means = last in first out

#include "stack_queue.h"
#include <iostream>

Stack::Stack()
    : top(nullptr), size(0)
{
}

Stack::Stack(const Stack& other)
    : top(nullptr), size(0)
{

    if (other.top == nullptr)
        return;

    std::size_t n = other.size;
    int* temp = new int[n];

    std::size_t i = 0;
    for (Node* cur = other.top; cur != nullptr; cur = cur->next)
    {
        temp[i++] = cur->data;
    }

    for (std::size_t k = n; k > 0; --k)
    {
        Push(temp[k - 1]);
    }

    delete[] temp;
}

Stack& Stack::operator=(const Stack& other)
{
    if (this == &other)
        return *this;

    Clear();

    if (other.top == nullptr)
        return *this;

    std::size_t n = other.size;
    int* temp = new int[n];

    std::size_t i = 0;
    for (Node* cur = other.top; cur != nullptr; cur = cur->next)
    {
        temp[i++] = cur->data;
    }

    for (std::size_t k = n; k > 0; --k)
    {
        Push(temp[k - 1]);
    }

    delete[] temp;

    return *this;
}

Stack::~Stack()
{
    Clear();
}

void Stack::Push(int value)
{
    Node* n = new Node;
    n->data = value;
    n->next = top;

    top = n;
    ++size;
}

bool Stack::Pop()
{
    if (IsEmpty())
    {

        std::cout << "Stack is empty. Nothing to pop.\n";
        return false;
    }

    Node* doomed = top;
    top = top->next;

    delete doomed;
    --size;

    return true;
}

bool Stack::Peek(int& out) const
{
    if (IsEmpty())
        return false;

    out = top->data;
    return true;
}

bool Stack::IsEmpty() const
{
    return top == nullptr;
}

std::size_t Stack::GetSize() const
{
    return size;
}

void Stack::Clear()
{
    while (top != nullptr)
    {
        Node* doomed = top;
        top = top->next;
        delete doomed;
    }
    size = 0;
}



// queue ideas
// Q means = first in first out

// add to back
// pop from front (edge case empty)
// peek front (edge case empty)
// empty
// size
// clear