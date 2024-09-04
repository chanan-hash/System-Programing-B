// Authors: Chanan helman
// chananhelman@gmail.com

#pragma once

#include <iostream>
#include <queue> // for the iterators
#include <sstream>
#include <stack> // for the iterators
#include <stdexcept>
#include <string>
#include <vector>

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
            throw runtime_error("The parent has the maximum number of children");
        }
        parent->add_child(child);
        size++;
    }

    //  class inorder_iterator;
    class preorder_iterator;
    class postorder_iterator;
    class inorder_iterator;
    class BFS_iterator;
    class DFS_iterator;

    // The iterators class

    // An inorder iterator - Left, Root, Right
    class inorder_iterator
    {
    private:
        // Node<T> *current;
        stack<Node<T> *> s;

    public:
        inorder_iterator(Node<T> *root)
        {
            // push all the left children of the root
            s.push(nullptr); // to know when to stop
            while (root != nullptr)
            {
                s.push(root);
                if (!root->children.empty() && root->children.size() > 0)

                {
                    root = root->children[0]; // the left child, going over an array
                }
                else
                {
                    root = nullptr;
                }
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
        inorder_iterator &operator++()
        {
            Node<T> *node = s.top();
            s.pop();
            if (!node->children.empty() && node->children.size() > 1)
            {
                Node<T> *right = node->children[1];
                while (right != nullptr)
                {
                    s.push(right);
                    if (!right->children.empty() && right->children.size() > 0)
                    {
                        right = right->children[0];
                    }
                    else
                    {
                        right = nullptr;
                    }
                }
            }

            return *this; // Return a reference to this iterator to allow chaining.
        }

        // comparison operators

        bool operator==(const inorder_iterator &other) const
        {
            return s.top() == other.s.top();
        }

        bool operator!=(const inorder_iterator &other) const
        {
            return !(*this == other);
        }
    };

    // An preorder iterator - Root, Left, Right
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
        T &operator*() { return postorder[index]->get_data(); }

        Node<T> *operator->() { return postorder[index]; }

        postorder_iterator &operator++()
        {
            index++;      // increase the index will go over the vector to the next node
            return *this; // Return a reference to this iterator to allow chaining.
        }

        // comparison operators
        bool operator==(const postorder_iterator &other) const { return postorder.size() - index == other.postorder.size() - other.index; } // going according the indexes because using vector
        bool operator!=(const postorder_iterator &other) const
        {
            return !(*this == other);
        }
    };

    class DFS_iterator
    {
    private:
        stack<Node<T> *> s;

    public:
        DFS_iterator(Node<T> *root)
        {
            if (root == nullptr)
            {
                return;
            }
            s.push(root); // to start the DFS from the root
        }

        // operators for the iteration itself
        T &operator*() const // getting node's value
        {
            return s.top()->value;
        }

        Node<T> *operator->() const // getting the node
        {
            return s.top();
        }

        // The DFS itself
        DFS_iterator &operator++()
        {
            Node<T> *node = s.top();                             // getting the top node
            s.pop();                                             // removing the top node
            for (int i = node->children.size() - 1; i >= 0; i--) // going over the children of the node
            {
                if (node->children[i] != nullptr) // if the child is not null
                {
                    s.push(node->children[i]); // pushing the children to the stack
                }
            }

            return *this; // return a reference to this iterator to allow chaining
        }

        // comparison operators
        bool operator==(const DFS_iterator &other) const
        {
            return s == other.s; // comparing the stacks or to compare the size of the stack or the references
        }

        bool operator!=(const DFS_iterator &other) const
        {
            return !(*this == other);
        }
    };

    class BFS_iterator
    {
    private:
        queue<Node<T> *> q;

    public:
        BFS_iterator(Node<T> *root)
        {
            if (root == nullptr)
            {
                return;
            }
            q.push(root); // to start the BFS from the root
        }

        // operators for the iteration itself
        T &operator*() const
        {
            return q.front()->value;
        }

        Node<T> *operator->() const
        {
            return q.front();
        }

        // The BFS itself
        BFS_iterator &operator++()
        {
            Node<T> *node = q.front(); // getting the first node in the queue
            q.pop();
            for (int i = 0; i < node->children.size(); i++) // going over the children of the node
            {
                if (node->children[i] != nullptr) // if the child is not null
                {
                    q.push(node->children[i]); // pushing the children to the queue
                }
            }

            return *this;
        }

        // comparison operators
        bool operator==(const BFS_iterator &other) const
        {
            return q == other.q; // comparing the queues or to compare the size of the queue or the references
        }

        bool operator!=(const BFS_iterator &other) const
        {
            return !(*this == other);
        }
    };

    // methods to start and end the iterators
    inorder_iterator begin_inorder()
    {
        return inorder_iterator(root);
    }

    inorder_iterator end_inorder()
    {
        return inorder_iterator(nullptr);
    }

    preorder_iterator begin_preorder()
    {
        return preorder_iterator(root);
    }

    preorder_iterator end_preorder()
    {
        return preorder_iterator(nullptr);
    }

    postorder_iterator begin_postorder()
    {
        return postorder_iterator(root);
    }

    postorder_iterator end_postorder()
    {
        return postorder_iterator(nullptr);
    }

    BFS_iterator begin_BFS()
    {
        return BFS_iterator(root);
    }

    BFS_iterator end_BFS()
    {
        return BFS_iterator(nullptr);
    }

    DFS_iterator begin_DFS()
    {
        return DFS_iterator(root);
    }

    DFS_iterator end_DFS()
    {
        return DFS_iterator(nullptr);
    }
};
