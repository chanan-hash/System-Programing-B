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
#include <algorithm> // for the heap

#include "Node.hpp"          // include the node class
#include <SFML/Graphics.hpp> // for the graphics

template <typename T, int K = 2> // for generic Tree, and K = 2 as default
class Tree
{

private:
    Node<T> *root;        // The root of the tree
    size_t size;          // The size of the tree
    int max_children = K; // The maximum number of children for each node

public:
    //  class inorder_iterator;
    class preorder_iterator;
    class postorder_iterator;
    class inorder_iterator;
    class BFS_iterator;
    class DFS_iterator;
    // class TreeToHeap;

    Tree() : root(nullptr), size(0) {}                   // constructor with the root value as initial list
    Tree(T value) : root(new Node<T>(value)), size(1) {} // constructor with the root value as initial list

    ~Tree() // destructor will use the iterators to delete all the nodes
    {
        // we know that tree is connected so we can use the BFS to delete all the nodes
        BFS_iterator it = begin_BFS();
        BFS_iterator previous = it;
        BFS_iterator end = end_BFS();
        while (it != end)
        {
            previous = it;
            ++it;
            previous->delete_children(); // delete the children of the node, the vector doing it by itself
        }
        root = nullptr;

        // delete the root
        delete[] root;
    }

    void add_root(Node<T> *node)
    {
        if (root != nullptr)
        {
            throw runtime_error("The root already exists");
        }
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
                if (!root->get_childrens().empty() && root->get_childrens().size() > 0 && root->get_childrens()[0] != nullptr)
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
            if (node->get_childrens().size() > 1 && node->get_childrens()[1] != nullptr)
            {
                Node<T> *right = node->get_childrens()[1]; // the right child
                s.push(right);                             // pushing the right child
                Node<T> *left = right;                     // the left child of the right child
                while (left->get_childrens().size() > 0 && left->get_childrens()[0] != nullptr)
                {
                    left = left->get_childrens()[0]; // going over the left children
                    s.push(left);                    // pushing the left child
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
            index = 0;

            if (root == nullptr) // if the root is null
            {
                return;
            }

            stack<Node<T> *> s;
            s.push(root);
            Node<T> *p = nullptr; // previous node

            while (!s.empty())
            {
                Node<T> *node = s.top();
                //  if we are going down the tree
                if (p == nullptr || (p->get_childrens().size() > 0 && p->get_childrens()[0] == node) || (p->get_childrens().size() > 1 && p->get_childrens()[1] == node))
                {
                    // if he has left child
                    if (node->get_childrens().size() > 0 && node->get_childrens()[0] != nullptr)
                    {
                        s.push(node->get_childrens()[0]); // go left
                    }
                    // if he has right child
                    else if (node->get_childrens().size() > 1 && node->get_childrens()[1] != nullptr)
                    {
                        s.push(node->get_childrens()[1]); // go right
                    }
                    else
                    { // leaf
                        postorder.push_back(node);
                        s.pop();
                    }
                }

                // if we are going up the tree from left child
                else if (node->get_childrens().size() > 0 && p == node->get_childrens()[0])
                {
                    if (node->get_childrens().size() > 1 && node->get_childrens()[1] != nullptr)
                    { // has right child
                        s.push(node->get_childrens()[1]);
                    }
                    else
                    {
                        postorder.push_back(node);
                        s.pop();
                    }
                    // if we are going up the tree from right child
                }
                else if (node->get_childrens().size() > 1 && p == node->get_childrens()[1])
                {
                    postorder.push_back(node);
                    s.pop();
                }
                p = node;
            }
        }

        // operator for the iteration itself
        T &operator*() { return postorder[index]->get_value(); }

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
            return q.front()->get_value();
        }

        Node<T> *operator->() const
        {
            return q.front();
        }

        // The BFS itself
        BFS_iterator &operator++()
        {
            if (q.empty())
            {
                return *this;
            }

            Node<T> *node = q.front(); // getting the first node in the queue
            q.pop();
            for (size_t i = 0; i < node->children.size(); i++) // going over the children of the node
            {
                if (node->get_childrens()[i] != nullptr) // if the child is not null
                {
                    q.push(node->get_childrens()[i]); // pushing the children to the queue
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

    class TreeToHeap
    {
    private:
        vector<Node<T> *> heap;
        int index;

    public:
        TreeToHeap(Node<T> *root)
        {
            index = 0; // initial index in the ++ operator we will increase it
            if (root == nullptr)
            {
                return;
            }
            BFS_iterator it = BFS_iterator(root); // using the BFS iterator to go over the tree
            BFS_iterator end = BFS_iterator(nullptr);
            // scanning the tree using BFS, and pushing the nodes to the heap
            while (it != end)
            {
                heap.push_back(it.operator->()); // pushing the nodes to the heap
                ++it;
            }

            std::make_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b)
                           { return a->get_value() < b->get_value(); });
        }

        // operators for the iteration itself
        T &operator*() { return heap[index]->get_value(); }

        Node<T> *operator->() { return heap[0]; }

        TreeToHeap &operator++()
        {
            // using the std pop_heap function to pop the root of the heap
            std::pop_heap(heap.begin(), heap.end() - index, [](Node<T> *a, Node<T> *b)
                          { return a->get_value() < b->get_value(); });
            index++; // increasing the index to go over the heap
            return *this;
        }

        // comparison operators
        bool operator==(const TreeToHeap &other) const { return heap.size() - index == other.heap.size() - other.index; } // going according the indexes because using vector
        bool operator!=(const TreeToHeap &other) const
        {
            return !(*this == other);
        }
    };

    // according to the assignment instructions we need to use the DFS iterator if K is not 2
    // This would change the tree-traversal if needed iterators to the DFS iterators
    using iterator_in_order = typename std::conditional<K == 2, inorder_iterator, DFS_iterator>::type;
    using iterator_pre_order = typename std::conditional<K == 2, preorder_iterator, DFS_iterator>::type;
    using iterator_post_order = typename std::conditional<K == 2, postorder_iterator, DFS_iterator>::type;

    // Methods to start and end the iterators
    BFS_iterator begin_BFS()
    {
        return BFS_iterator(root);
    }

    BFS_iterator end_BFS()
    {
        return BFS_iterator(nullptr);
    }

    iterator_in_order begin_in_order()
    {
        return iterator_in_order(root);
    }

    iterator_in_order end_in_order()
    {
        return iterator_in_order(nullptr);
    }

    iterator_pre_order begin_pre_order()
    {
        return iterator_pre_order(root);
    }

    iterator_pre_order end_pre_order()
    {
        return iterator_pre_order(nullptr);
    }

    iterator_post_order begin_post_order()
    {
        return iterator_post_order(root);
    }

    iterator_post_order end_post_order()
    {
        return iterator_post_order(nullptr);
    }

    DFS_iterator begin_DFS()
    {
        return DFS_iterator(root);
    }

    DFS_iterator end_DFS()
    {
        return DFS_iterator(nullptr);
    }
    // Tree to Heap iterator
    TreeToHeap begin_TreeToHeap()
    {
        return TreeToHeap(root);
    }

    TreeToHeap end_TreeToHeap()
    {
        return TreeToHeap(nullptr);
    }

    // drawing the tree using the graphics

    // Overload the << operator
    friend std::ostream &operator<<(std::ostream &os, const Tree<T> &tree)
    {
        if (!tree.root)
        {
            os << "Tree is empty";
            return os;
        }

        // Create an SFML window
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

        // Main loop
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);

            // Draw the tree
            drawTree(window, tree);

            window.display();
        }

        return os;
    }

    // Function to draw the tree
    static void drawTree(sf::RenderWindow &window, const Tree<T> &tree)
    {
        if (!tree.root)
            return;
        drawNode(window, tree.root, 400, 50, 200, 100);
    }

    // Function to draw a node
    static void drawNode(sf::RenderWindow &window, Node<T> *node, float x, float y, float offsetX, float offsetY)
    {
        if (!node)
            return;

        // Draw the node
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw the node value
        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        {
            // Handle error
        }
        sf::Text text;
        text.setFont(font);
        text.setString(to_string(node->get_value()));
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 10, y + 10);
        window.draw(text);

        // Draw the children
        float childX = x - offsetX;
        float childY = y + offsetY;
        for (Node<T> *child : node->children)
        {
            // Draw the edge
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + 20, y + 20)),
                sf::Vertex(sf::Vector2f(childX + 20, childY + 20))};
            window.draw(line, 2, sf::Lines);

            // Recursively draw the child node
            drawNode(window, child, childX, childY, offsetX / 2, offsetY);

            childX += offsetX;
        }
    }
};
