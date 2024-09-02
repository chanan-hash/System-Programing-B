// Authors: Chanan helman
// chananhelman@gmail.com

#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stack> // for the iterators
#include <queue> // for the iterators

#include "Node.hpp" // include the node class

template <typename T, int K = 2> // for generic Tree, and K = 2 as default
class Tree
{
private:
    Node<T> *root;        // The root of the tree
    size_t size;          // The size of the tree
    int max_children = K; // The maximum number of children for each node

public:
    Tree() : root(nullptr), size(0) {} // initial list
    ~Tree() {}                         // destructor wiil use the iterators to delete all the nodes

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
            throw runtime_error "The parent has reached the maximum number of children";
        }
        parent->add_child(child);
        size++;
    }
};
// The iterators class

// An inorder iterator - Left, Root, Right
template <typename T>
class inorder_iterator
{
private:
    Node<T> *current;
    stack<Node<T> *> s;

public:
    inorder_irerator(Node<T> *root)
    {
        // push all the left children of the root
        current = root;
        while (current != nullptr)
        {
            s.push(current);
            if (!root->children.empty())
            {
                current = root->children[0]; // the left child, going over an array
            }
            else
            {
                current = nullptr;
            }
        }
    }

    // operators for the iteration itself
    T &operator*() const // getting the value of the current node
    {
        return current->value;
    }

    // getting the pointer to the current node
    Node<T> *operator->() const
    {
        return &current->value;
    }

    // the ++ operator
    inorder_iterator &operator++()
    {
        if (s.empty())
        {
            current = nullptr;
            return *this;
        }
        current = s.top();
        s.pop();
        if (!current->children.empty() && current->children.size() > 1)
        {
            Node<T> *node_right = current->children[1]; // means there is a right child to go over
            while (node_right != nullptr)
            {
                s.push(node_right);
                if (!node_right->children.empty())
                {
                    node_right = node_right->children[0];
                }
                else
                {
                    node_right = nullptr;
                }
            }
        }
        return *this;
    }

    // comparison operators

    bool operator==(const inorder_iterator &other) const
    {
        return current == other.current;
    }

    bool operator!=(const inorder_iterator &other) const
    {
        return !(*this == other);
    }
};

// An preorder iterator - Root, Left, Right
template <typename T>
class preorder_iterator
{
private:
    stack<Node<T> *> s;

public:
    preorder_iterator(Node<T> *root)
    {
        s.push(nullptr); // to know when to stop
        if (root != nullptr)
        {
            s.push(root);
        }
    }

    // operators for the iteration itself
    T &operator*() const // getting the value of the current node
    {
        return s.top()->value;
    }

    // getting the pointer to the current node
    Node<T> *operator->() const
    {
        return s.top();
    }

    // the ++ operator
    preorder_iterator &operator++()
    {
        Node<T> *node = s.top();
        s.pop();
        // pushing right child first
        if (node->get_childrens().size() > 1 && node->get_childrens()[1] != nullptr)
        {
            s.push(node->get_childrens()[1]);
        }
        // left child
        if (node->get_childrens().size() > 0 && node->get_childrens()[0] != nullptr)
        {
            s.push(node->get_childrens()[0]);
        }

        return *this; // Return a reference to this iterator to allow chaining.
    }

    // comparison operators
    bool operator==(const preorder_iterator &other) const
    {
        return s.top() == other.s.top();
    }

    bool operator!=(const preorder_iterator &other) const
    {
        return !(*this == other);
    }
};

// An postorder iterator - Left, Right, Root

template <typename T>
class postorder_iterator
{
private:
    vector<Node<T> *> postorder;
    int index;

public:
    postorder_iterator(Node<T> *root)
    {
        stack<Node<T> *> s;
        s.push(root);
        while (!s.empty())
        {
            Node<T> *node = s.top();
            s.pop();
            postorder.push_back(node);
            for (int i = 0; i < node->get_childrens().size(); i++)
            {
                s.push(node->get_childrens()[i]);
            }
        }
        index = 0;
    }

    // operator for the iteration itself
    T &operator*() { return post_order[index]->get_data(); }

    Node<T> *operator->() { return post_order[index]; }

    post_order_iterator &operator++()
    {
        index++; // increase the index will go over the vector to the next node
        return *this; // Return a reference to this iterator to allow chaining.
    }

    // comparison operators
    bool operator==(const post_order_iterator &other) const { return post_order.size() - index == other.post_order.size() - other.index; } // going according the indexes because using vector
    bool operator!=(const post_order_iterator &other) const
    {
        return !(*this == other);
    }
};

// BFS iterator
// DFS iterator