#pragma once

#include <cstddef> 

class Tree 
{
private:

// tree node structure
// data
// left branch
// right branch

    struct Node
    {
        int data;
        Node* left;
        Node* right;

        Node(int value);
    };

    // tree root
    Node* root;

    // tree size
    std::size_t size;

    // recursive insert and remove
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);

    // minimum node
    Node* findMin(Node* node) const;

    // binary search?
    bool contains(Node* node, int value) const;

    // Depth-first search helpers
    void inorder(Node* node) const;
    void preorder(Node* node) const;
    void postorder(Node* node) const;

    // clear
    void clear(Node* node);

    // copy
    Node* copy(Node* node);




public:

    // constructors and destructors
    Tree();
    Tree(const Tree& other);
    Tree& operator=(const Tree& other);
    ~Tree();

    // non-recursive base operations
    bool Insert(int value);
    bool Remove(int value);
    bool Contains(int value) const;

    // printing
    void PrintInOrder() const;
    void PrintPreOrder() const;
    void PrintPostOrder() const;
    void PrintLevelOrder() const;

    // other helpers
    bool IsEmpty() const;
    std::size_t GetSize() const;
    void Clear();
    void InitSample();


};