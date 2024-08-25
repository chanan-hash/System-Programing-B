#pragma once
// Author: chanan-helman
/**
 * This class is a node class for our k-nary tree, it contains a value and a vector of children nodes.
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T> // for generic Node
class Node
{
public:
    T value;
    vector<Node<T> *> children; // The children of the node

    explicit Node(T value) : value(value) {} // initial list

    // getters, inlines for performance
    T &get_value() const
    {
        return value;
    }

    const vector<Node<T> *> &get_childrens() const { return children; }

    // add a child to the node
    void add_child(Node<T> *child)
    {
        children.push_back(child);
    }

    // remove a child from the node
    void remove_child(Node<T> *child);

    void delete_children()
    {
        children.clear();
    };

    // String representation of the node
    // string to_string() const
    // {
    //     stringstream ss;
    //     ss << value;
    //     return ss.str();
    // }

    /**
     * To string function. shpw the node value as string
     */
    string to_string() const
    {
        string s;
        if (is_floating_point<T>::value)
        {
            s = to_string(value);
            ostringstrseam os;
            os << value; // or get_value()
            s = os.str();
        }
        else
        {
            s = to_string(value); // or get_value()
        }
        return s;
    }
};