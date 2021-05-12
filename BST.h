//
// Created by Karen Axon
// File: BST.h
// Date: October 15, 2020
// Purpose: This program implements a BST template class.
// Input: None
// Process: It provides the ability to insert and remove elements into and
// from the BST. It can also check to see if the BST contains an specific
// element, if it is empty, its size and it returns data showing the leaf
// count, its height and the ancestors of an item. It also returns a string
// representation of the in order, pre order or post order traversals.
// Output: Standard output.


#ifndef BST_TEMPLATE_BST_H
#define BST_TEMPLATE_BST_H

#include <string>
#include <sstream>
using namespace std;

template <typename T>
class BST {

private:
    struct Node {
        T data;
        Node * left;
        Node * right;
    };
    Node * root;

public:
    BST();
    // Default constructor
    // precondition: none
    // postcondition: An empty BST with root set to null.

    ~BST();
    // Destructor
    // Removes all elements from the BST.
    // precondition: none
    // postcondition: The BST will be deleted from the heap when the
    // program terminates.

    void destroyTree(Node *&);
    // Destructor helper function
    // precondition: none
    // postcondition: The BST will be deleted from the heap when the
    // program terminates.

    bool empty();
    // It determines if the BST is empty.
    // precondition: none
    // postcondition: Returns true if so, else false.

    bool contains(T);
    // It searches the BST with recursion to determine if a given value is
    // present.
    // precondition: none
    // postcondition: Returns true if so, else false.

    bool containsHelper(Node *&, T);
    // Contains function helper function
    // precondition: none
    // postcondition: Returns true if so, else false.

    void insert(T);
    // It inserts the element with recursion passed in as a parameter into the
    // BST.
    // precondition: Assume no duplicate values.
    // postcondition: A new noe with the element.

    void insert(Node *&, Node *&);
    // Insert function helper function
    // precondition: Assume no duplicate values.
    // postcondition: A new noe with the element.

    void remove(T);
    // It removes the specified value from the BST.
    // precondition: An existing node with the value.
    // postcondition: The node removed from the BST.

    void remove(Node *&, T);
    // Remove function helper function
    // precondition: An existing node with the value.
    // postcondition: The node removed from the BST.

    void makeDeletion(Node *&, int);
    // Remove and remove helper functions helper.
    // precondition: An existing node with the value.
    // postcondition: The node removed from the BST.

    int size();
    // It returns the count of nodes in the BST.
    // precondition: none
    // postcondition: The count of nodes in the BST.

    int size(Node *);
    // Size function helper function.
    // precondition: none
    // postcondition: The count of nodes in the BST.

    string getPreOrderTraversal();
    // It returns a string of elements in the order specified by the pre-order
    // traversal of the BST.
    // precondition: None
    // postcondition: A string representation of the BST.

    void getPreOrderTraversal(Node *, stringstream &);
    // getPreOrderTraversal function helper function.
    // precondition: None
    // postcondition: A string representation of the BST.

    string getInOrderTraversal();
    // It returns a string of elements in the order specified by the in-order
    // traversal of the BST.
    // precondition: None
    // postcondition: A string representation of the BST.

    void getInOrderTraversal(Node *, stringstream &);
    // getInOrderTraversal function helper function.
    // precondition: None
    // postcondition: A string representation of the BST.

    string getPostOrderTraversal();
    // It returns a string of elements in the order specified by the post-order
    // traversal of the BST.
    // precondition:
    // postcondition: A string representation of the BST.

    void getPostOrderTraversal(Node *, stringstream &);
    // getPostOrderTraversal function helper function.
    // precondition: None
    // postcondition: A string representation of the BST.

    int getHeight();
    // It returns height of the BST.
    // precondition: None
    // postcondition: An integer indicating empty (0) or the correct height is
    // returned.

    int getHeight(Node * ptr);
    // getHeight function helper function.
    // precondition:None
    // postcondition: An integer indicating empty (0) or the correct height is
    // returned.

    int getLeafCount();
    // It returns the count of nodes in the BST that do not have any children.
    // precondition: None
    // postcondition: An integer indicating the correct leaf count is returned.

    int getLeafCount(Node*);
    // getLeafCount function helper function.
    // precondition: None
    // postcondition: An integer indicating the correct leaf count is returned.

    string getAncestors(T);
    // It returns the elements that are the ancestor(s) of the given node.
    // precondition: None
    // postcondition: A string is returned. Empty is the values is not
    // present. Otherwise, the most immediate ancestor will be the first in the
    // list.

    bool getAncestorsHelper(Node *, T, stringstream &);
    // getAncestors function helper function.
    // precondition: None
    // postcondition: A string is returned. Empty is the values is not
    // present. Otherwise, the most immediate ancestor will be the first in the
    // list.

};


template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template <typename T>
void BST<T>::destroyTree(Node *&ptr) {
    if (ptr != nullptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }
    ptr = nullptr;
}

template <typename T>
bool BST<T>::empty() {
    if (root == nullptr)
        return true;
    else
        return false;
}

template <typename T>
bool BST<T>::contains(T item) {
    return containsHelper(root, item);
}

template <typename T>
bool BST<T>::containsHelper(Node *&ptr, T item) {

    if (ptr == nullptr)  // if empty
        return false;

    if (ptr->data == item)  // if same as root
        return true;

    bool leftSide = containsHelper(ptr->left, item);  // if smaller than root
    if (leftSide) return true;

    bool rightSide = containsHelper(ptr->right, item); // if larger than root
    return rightSide;
}

template <typename T>
void BST<T>::insert(T item) {
    Node * newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template <typename T>
void BST<T>::insert(Node *& ptr, Node *& newNode) {
    if (ptr == nullptr)
        ptr = newNode;
    else if (ptr->data > newNode->data)
        insert(ptr->left, newNode);
    else
        insert(ptr->right, newNode);
}

template <typename T>
void BST<T>::remove(T item) {
    remove(root, item);
}

template <typename T>
void BST<T>::remove(Node *& ptr, T item) {
    if (ptr != nullptr) {
        if (ptr->data > item)
            remove(ptr->left, item);
        else if (ptr->data < item)
            remove(ptr->right, item);
        else
            makeDeletion(ptr, item);
    }
}

template <typename T>
void BST<T>::makeDeletion(Node *& ptr, int item) {
    Node * curr = nullptr;
    if (ptr != nullptr) {
        if (ptr->left == nullptr) {
            curr = ptr;
            ptr = ptr->right;
            delete curr;
        } else if (ptr->right == nullptr) {
            curr = ptr;
            ptr = ptr->left;
            delete curr;
        } else {
            curr = ptr->right;
            while (curr->left != nullptr)
                curr = curr->left;
            ptr->data = curr->data;
            remove(ptr->right, curr->data);
        }
    }
}

template <typename T>
int BST<T>::size () {
    // Invoke helper to recursively count the nodes
    return size(root);
}

template <typename T>
int BST<T>::size (Node * ptr) {
    if(ptr == nullptr)
        return 0;
    else
        return 1 + (size(ptr->right) + size(ptr->left));
}

template <typename T>
string BST<T>::getPreOrderTraversal() {
    stringstream ss;
    getPreOrderTraversal(root, ss);

    return ss.str();
}

template <typename T>
void BST<T>::getPreOrderTraversal(Node * ptr, stringstream &ss) {
    if (ptr != nullptr) {
        ss << ptr->data << "  ";
        getPreOrderTraversal(ptr->left, ss);
        getPreOrderTraversal(ptr->right, ss);
    }
}

template<typename T>
string BST<T>::getInOrderTraversal() {
    stringstream ss;
    getInOrderTraversal(root, ss);
    return ss.str();
}

template<typename T>
void BST<T>::getInOrderTraversal(Node * ptr, stringstream &ss) {
    if (ptr != nullptr) {
        // recur left
        getInOrderTraversal(ptr->left, ss);
        ss << ptr->data << "  ";
        // recur right
        getInOrderTraversal(ptr->right, ss);
    }
}

template<typename T>
string BST<T>::getPostOrderTraversal() {
    stringstream ss;
    getPostOrderTraversal(root, ss);
    return ss.str();
}

template<typename T>
void BST<T>::getPostOrderTraversal(Node * ptr, stringstream &ss) {
    if (ptr != nullptr) {
        // recur left
        getPostOrderTraversal(ptr->left, ss);
        // recur right
        getPostOrderTraversal(ptr->right, ss);
        ss << ptr->data << "  ";
    }
}

template<typename T>
int BST<T>::getHeight() {
    return getHeight(root);
}

template<typename T>
int BST<T>::getHeight(Node * ptr) {
    if(ptr == nullptr)
        return 0;

    if(ptr->left == nullptr && ptr->right == nullptr)
        return 1;
    else {
        int rPtr = getHeight(ptr->right), lPtr = getHeight(ptr->left);
        return (rPtr > lPtr) ? 1+rPtr : 1+lPtr;
    }
}

template<typename T>
int BST<T>::getLeafCount() {
    return getLeafCount(root);
}

template<typename T>
int BST<T>::getLeafCount(Node * ptr) {
    if(ptr == nullptr)
        return 0;
    if(ptr->left == nullptr && ptr->right == nullptr)
        return 1;
    else
        return getLeafCount(ptr->left) + getLeafCount(ptr->right);
}

template<typename T>
string BST<T>::getAncestors(T key) {
    stringstream ss;
    getAncestorsHelper(root, key, ss);
    return ss.str();
}

template<typename T>
bool BST<T>::getAncestorsHelper(Node * ptr, T key, stringstream &ss) {
    if(!contains(key)) {
        ss << " Not on BST";
        return false;
    }
    // base case
    if(ptr == nullptr) {
        ss << " ";
        return false;
    }

    if(ptr->data == key) {
        ss << " ";
        return true;
    }

    // return ancestors if given node is found in left or right subtrees
    if(root->data < key) {
        getAncestorsHelper(ptr->right, key, ss);
        ss << ptr->data << " ";
    }else if(root->data > key) {
        getAncestorsHelper(ptr->left, key, ss);
        ss << ptr->data << " ";
    }
    return true;
}

#endif //BST_TEMPLATE_BST_H
