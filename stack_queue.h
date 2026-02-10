#pragma once

#include <cstddef> 

// Stack (Last in first out)
class Stack
{
private:

    struct Node
    {
        int data;
        Node* next;
    };

    Node* top;
    std::size_t size;

public:

    // Constructors / Destructor
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    void Push(int value);
    bool Pop();
    bool Peek(int& out) const;

    // helpers
    bool IsEmpty() const;
    std::size_t GetSize() const;
    void Clear();
};



// Queue (first in first out)
class Queue
{
private:

    struct Node
    {
        int data;
        Node* next;
    };

    Node* front;
    Node* back;
    std::size_t size;

public:

    // Constructors / Destructor
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();

    void Enqueue(int value);
    bool Dequeue();
    bool PeekFront(int& out) const;

    // helpers
    bool IsEmpty() const;
    std::size_t GetSize() const;
    void Clear();
};
