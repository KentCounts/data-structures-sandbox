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