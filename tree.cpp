#include "tree.h"
#include <iostream>
#include <queue>


// Node Constructor
Tree::Node::Node(int value)
    : data(value), left(nullptr), right(nullptr)
{
    // Literally just pointers
}

// Tree Constructors / Destructor
Tree::Tree()
    : root(nullptr), size(0)
{
    // just a root pointer and a 0 size
}

Tree::Tree(const Tree& other)
    : root(nullptr), size(0)
{
    // Copy a tree into another tree
    root = copy(other.root);
    size = other.size;
}

Tree& Tree::operator=(const Tree& other)
{
    if (this != &other)
    {
        Clear();

        // Deep copy
        root = copy(other.root);
        size = other.size;
    }
    return *this;
}

Tree::~Tree()
{
    Clear();
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
    if (node == nullptr)
        return;

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void Tree::preorder(Node* node) const
{
    if (node == nullptr)
        return;

    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void Tree::postorder(Node* node) const
{
    if (node == nullptr)
        return;

    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

void Tree::clear(Node* node)
{
    if (node == nullptr)
        return;

    clear(node->left);
    clear(node->right);

    delete node;
}

Tree::Node* Tree::copy(Node* node)
{
    if (node == nullptr)
        return nullptr;

    Node* newNode = new Node(node->data);

    newNode->left = copy(node->left);
    newNode->right = copy(node->right);

    return newNode;
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
    inorder(root);
    std::cout << "\n";
}

void Tree::PrintPreOrder() const
{
    preorder(root);
    std::cout << "\n";
}

void Tree::PrintPostOrder() const
{
    postorder(root);
    std::cout << "\n";
}

void Tree::PrintLevelOrder() const
{
    if (root == nullptr)
        return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }

    std::cout << "\n";
}

// Other Helpers
bool Tree::IsEmpty() const
{
    return root == nullptr;
}

std::size_t Tree::GetSize() const
{
    return size;
}

void Tree::Clear()
{
    clear(root);
    root = nullptr;
    size = 0;
}

void Tree::InitSample()
{
    Clear();

    Insert(50);
    Insert(30);
    Insert(70);
    Insert(20);
    Insert(40);
    Insert(60);
    Insert(80);
}