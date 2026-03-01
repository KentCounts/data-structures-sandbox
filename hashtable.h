#pragma once

#include <cstddef>

class HashTable
{
private:

    struct Node
    {
        int key;
        int value;
        Node* next;

        Node(int k, int v);
    };

    Node** table;
    std::size_t capacity;
    std::size_t size;

    std::size_t hash(int key) const;

    Node* findNode(int key) const;
    Node* findNodeInBucket(std::size_t idx, int key) const;

    void clearBucket(Node* head);
    Node* copyBucket(Node* head);

    void resizeIfNeeded();
    void rehash(std::size_t newCapacity);

public:

    explicit HashTable(std::size_t initialCapacity = 11);
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);
    ~HashTable();

    bool Insert(int key, int value);
    bool Remove(int key);
    bool Contains(int key) const;
    bool Get(int key, int& outValue) const;

    bool IsEmpty() const;
    std::size_t GetSize() const;
    std::size_t GetCapacity() const;
    double LoadFactor() const;

    void Clear();
    void InitSample();

    void Print() const;
    void PrintBucket(std::size_t index) const;
};