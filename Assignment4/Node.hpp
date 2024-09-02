#pragma once
// Author: chanan-helman
// chananhelman@gmail.com

/**
 * This class is a node class for our k-nary tree, it contains a value and a vector of children nodes.
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string to_string(const string &str)
{
    return str;
}

template <typename T> // for generic Node
class Node
{
public:
    T value;
    vector<Node<T> *> children; // The children of the node

    explicit Node(T value) : value(value) {} // initial list

    // non const getter
    T &get_value()
    {
        return value;
    }

    // getters, inlines for performance
    const T &get_value() const
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
    void remove_child(Node<T> *child)
    {
        children.erase(std::remove(children.begin(), children.end(), child), children.end());
    }

    void delete_children()
    {
        children.clear();
    };

    /**
     * To string function. show the node value as string
     */
    string to_string() const
    {
        string s;
        if (std::is_floating_point<T>::value)
        {
            std::ostringstream os;
            os << get_value();
            s = os.str();
        }
        else
        {
            s = std::to_string(get_value());
        }
        return s;
    }
};