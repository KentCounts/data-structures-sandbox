#include "hashtable.h"

std::size_t HashTable::hash(int key) const
{

    return static_cast<std::size_t>(
        (key % static_cast<int>(capacity) + static_cast<int>(capacity))
        % static_cast<int>(capacity)
        );
}

HashTable::Node* HashTable::findNodeInBucket(std::size_t idx, int key) const
{
    Node* current = table[idx];

    while (current != nullptr)
    {
        if (current->key == key)
            return current;

        current = current->next;
    }

    return nullptr;
}

HashTable::Node* HashTable::findNode(int key) const
{
    std::size_t idx = hash(key);
    return findNodeInBucket(idx, key);
}

void HashTable::clearBucket(Node* head)
{
    while (head != nullptr)
    {
        Node* doomed = head;
        head = head->next;
        delete doomed;
    }
}

HashTable::Node* HashTable::copyBucket(Node* head)
{
    if (head == nullptr)
        return nullptr;

    Node* newHead = new Node(head->key, head->value);
    Node* tail = newHead;

    for (Node* cur = head->next; cur != nullptr; cur = cur->next)
    {
        tail->next = new Node(cur->key, cur->value);
        tail = tail->next;
    }

    return newHead;
}

void HashTable::resizeIfNeeded()
{
    if (capacity == 0)
        return;

    double lf = static_cast<double>(size) / static_cast<double>(capacity);
    if (lf > 0.75)
    {
        rehash(capacity * 2 + 1);
    }
}

void HashTable::rehash(std::size_t newCapacity)
{
    if (newCapacity < 1)
        newCapacity = 1;

    Node** oldTable = table;
    std::size_t oldCapacity = capacity;

    table = new Node * [newCapacity];
    capacity = newCapacity;

    for (std::size_t i = 0; i < capacity; ++i)
        table[i] = nullptr;

    for (std::size_t i = 0; i < oldCapacity; ++i)
    {
        Node* cur = oldTable[i];

        while (cur != nullptr)
        {
            Node* next = cur->next;
            std::size_t idx = hash(cur->key);

            cur->next = table[idx];
            table[idx] = cur;

            cur = next;
        }
    }

    delete[] oldTable;
}