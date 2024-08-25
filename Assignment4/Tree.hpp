#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "Node.hpp" // include the node class

template <typename T, int K = 2> // for generic Tree
class Tree
{
private:
    Node<T> *root;        // The root of the tree
    size_t size;          // The size of the tree
    int max_children = K; // The maximum number of children for each node

public:
    Tree() : root(nullptr), size(0) {} // initial list
    ~Tree() { clear() }                // destructor
    //    ~Tree() { root->delete_children(); } // destructor need to go over all the nodes and delete them

    void add_root(Node<T> *node)
    {
        this->root = node;
        size++;
    }

    Node<T> *get_root() const { return root; }

    // To add a sub node we need to give the parent, and then check if the parent has less than K children, if so we can add the child
    void add_sub_node(Node<T> *parent, Node<T> *child)
    {
        if (parent->get_childrens().size() >= K)
        {
            throw "The parent has reached the maximum number of children";
        }
        parent->add_child(child);
    }

    // clear function - going over the tree by the iterators and delete all the nodes

    // The iterator class
};