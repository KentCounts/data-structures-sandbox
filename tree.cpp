#include "tree.h"
#include <iostream>

// Node Constructor
Tree::Node::Node(int value)
    : data(value), left(nullptr), right(nullptr)
{
    // no logic yet
}

// Tree Constructors / Destructor
Tree::Tree()
    : root(nullptr), size(0)
{
    // no logic yet
}

Tree::Tree(const Tree& other)
    : root(nullptr), size(0)
{
    // no logic yet
}

Tree& Tree::operator=(const Tree& other)
{
    if (this != &other)
    {
        // no logic yet
    }
    return *this;
}

Tree::~Tree()
{
    // no logic yet
}

// Private Recursive Helpers
Tree::Node* Tree::insert(Node* node, int value)
{
    // no logic yet
    return node;
}

Tree::Node* Tree::remove(Node* node, int value)
{
    // no logic yet
    return node;
}

Tree::Node* Tree::findMin(Node* node) const
{
    // no logic yet
    return nullptr;
}

bool Tree::contains(Node* node, int value) const
{
    // no logic yet
    return false;
}

void Tree::inorder(Node* node) const
{
    // no logic yet
}

void Tree::preorder(Node* node) const
{
    // no logic yet
}

void Tree::postorder(Node* node) const
{
    // no logic yet
}

void Tree::clear(Node* node)
{
    // no logic yet
}

Tree::Node* Tree::copy(Node* node)
{
    // no logic yet
    return nullptr;
}

// Public Non Recursive Operations
bool Tree::Insert(int value)
{
    // no logic yet
    return false;
}

bool Tree::Remove(int value)
{
    // no logic yet
    return false;
}

bool Tree::Contains(int value) const
{
    // no logic yet
    return false;
}

// Printing
void Tree::PrintInOrder() const
{
    // no logic yet
}

void Tree::PrintPreOrder() const
{
    // no logic yet
}

void Tree::PrintPostOrder() const
{
    // no logic yet
}

void Tree::PrintLevelOrder() const
{
    // no logic yet
}

// Other Helpers
bool Tree::IsEmpty() const
{
    // no logic yet
    return false;
}

std::size_t Tree::GetSize() const
{
    // no logic yet
    return 0;
}

void Tree::Clear()
{
    // no logic yet
}

void Tree::InitSample()
{
    // no logic yet
}