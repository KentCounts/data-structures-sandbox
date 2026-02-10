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



// queue
// Q means = first in first out

Queue::Queue()
    : front(nullptr), back(nullptr), size(0)
{
}

Queue::Queue(const Queue& other)
    : front(nullptr), back(nullptr), size(0)
{
    for (Node* cur = other.front; cur != nullptr; cur = cur->next)
    {
        Enqueue(cur->data);
    }
}

Queue& Queue::operator=(const Queue& other)
{
    if (this == &other)
        return *this;

    Clear();

    for (Node* cur = other.front; cur != nullptr; cur = cur->next)
    {
        Enqueue(cur->data);
    }

    return *this;
}

Queue::~Queue()
{
    Clear();
}

void Queue::Enqueue(int value)
{
    Node* n = new Node;
    n->data = value;
    n->next = nullptr;

    if (IsEmpty())
    {
        front = back = n;
    }
    else
    {
        back->next = n;
        back = n;
    }

    ++size;
}

bool Queue::Dequeue()
{
    if (IsEmpty())
    {
        return false;
    }

    Node* doomed = front;
    front = front->next;
    delete doomed;

    --size;

    if (front == nullptr)
    {
        back = nullptr;
    }

    return true;
}

bool Queue::PeekFront(int& out) const
{
    if (IsEmpty())
        return false;

    out = front->data;
    return true;
}

bool Queue::IsEmpty() const
{
    return front == nullptr;
}

std::size_t Queue::GetSize() const
{
    return size;
}

void Queue::Clear()
{
    while (front != nullptr)
    {
        Node* doomed = front;
        front = front->next;
        delete doomed;
    }

    back = nullptr;
    size = 0;
}
