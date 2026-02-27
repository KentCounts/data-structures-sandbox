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

HashTable::Node::Node(int k, int v)
    : key(k), value(v), next(nullptr)
{
}

HashTable::HashTable(std::size_t initialCapacity)
    : table(nullptr), capacity(initialCapacity), size(0)
{
    if (capacity < 1)
        capacity = 1;

    table = new Node * [capacity];
    for (std::size_t i = 0; i < capacity; ++i)
        table[i] = nullptr;
}

HashTable::HashTable(const HashTable& other)
    : table(nullptr), capacity(other.capacity), size(other.size)
{
    if (capacity < 1)
        capacity = 1;

    table = new Node * [capacity];
    for (std::size_t i = 0; i < capacity; ++i)
        table[i] = nullptr;

    for (std::size_t i = 0; i < capacity; ++i)
    {
        table[i] = copyBucket(other.table[i]);
    }
}

HashTable& HashTable::operator=(const HashTable& other)
{
    if (this == &other)
        return *this;

    if (table != nullptr)
    {
        for (std::size_t i = 0; i < capacity; ++i)
        {
            clearBucket(table[i]);
            table[i] = nullptr;
        }
        delete[] table;
        table = nullptr;
    }

    capacity = other.capacity;
    size = other.size;

    if (capacity < 1)
        capacity = 1;

    table = new Node * [capacity];
    for (std::size_t i = 0; i < capacity; ++i)
        table[i] = nullptr;

    for (std::size_t i = 0; i < capacity; ++i)
    {
        table[i] = copyBucket(other.table[i]);
    }

    return *this;
}

HashTable::~HashTable()
{
    if (table != nullptr)
    {
        for (std::size_t i = 0; i < capacity; ++i)
        {
            clearBucket(table[i]);
            table[i] = nullptr;
        }

        delete[] table;
        table = nullptr;
    }

    capacity = 0;
    size = 0;
}

bool HashTable::Insert(int key, int value)
{
    if (findNode(key) != nullptr)
        return false;

    std::size_t idx = hash(key);

    Node* n = new Node(key, value);
    n->next = table[idx];
    table[idx] = n;

    ++size;
    resizeIfNeeded();
    return true;
}

bool HashTable::Remove(int key)
{
    std::size_t idx = hash(key);

    Node* current = table[idx];
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (prev == nullptr)
            {
                // removing head
                table[idx] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            delete current;
            --size;
            return true;
        }

        prev = current;
        current = current->next;
    }

    return false;
}

bool HashTable::Contains(int key) const
{
    return findNode(key) != nullptr;
}

bool HashTable::Get(int key, int& outValue) const
{
    Node* n = findNode(key);
    if (n == nullptr)
        return false;

    outValue = n->value;
    return true;
}

bool HashTable::IsEmpty() const
{
    return size == 0;
}

std::size_t HashTable::GetSize() const
{
    return size;
}

std::size_t HashTable::GetCapacity() const
{
    return capacity;
}

double HashTable::LoadFactor() const
{
    if (capacity == 0)
        return 0.0;

    return static_cast<double>(size) / static_cast<double>(capacity);
}