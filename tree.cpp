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
    if (node == nullptr)
    {
        return new Node(value);
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }
    // else duplicate: do nothing

    return node;
}

Tree::Node* Tree::remove(Node* node, int value)
{
    if (node == nullptr)
        return nullptr;

    if (value < node->data)
    {
        node->left = remove(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = remove(node->right, value);
    }
    else
    {
        // Found node to remove

        // Case 1: no left child
        if (node->left == nullptr)
        {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        }

        // Case 2: no right child
        if (node->right == nullptr)
        {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }

        // Case 3: two children
        // Replace with inorder successor (min of right subtree)
        Node* successor = findMin(node->right);
        node->data = successor->data;

        // Remove successor from right subtree
        node->right = remove(node->right, successor->data);
    }

    return node;
}

Tree::Node* Tree::findMin(Node* node) const
{
    if (node == nullptr)
        return nullptr;

    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

bool Tree::contains(Node* node, int value) const
{
    if (node == nullptr)
        return false;

    if (value == node->data)
        return true;

    if (value < node->data)
        return contains(node->left, value);

    return contains(node->right, value);
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
    // reject duplicates
    if (Contains(value))
        return false;

    root = insert(root, value);
    ++size;
    return true;
}

bool Tree::Remove(int value)
{
    if (!Contains(value))
        return false;

    root = remove(root, value);
    --size;
    return true;
}

bool Tree::Contains(int value) const
{
    return contains(root, value);
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