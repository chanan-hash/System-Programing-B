// Authors: Chanan helman
// chananhelman@gmail.com

#include <iostream>
#include <string>
#include <vector>
#include "complex.hpp"
#include "Node.hpp"


using namespace std;

int main()
{
    // Checking the complex class
    // Complex c1(1, 2);
    // Complex c2(1, -2);
    
    // cout << "c1: " << c1 << endl;
    // cout << "c2: " << c2 << endl;

    // cout << "c1 == c2: " << (c1 == c2) << endl;
    // cout << "c1 != c2: " << (c1 != c2) << endl;
    // cout << "c1 < c2: " << (c1 < c2) << endl;
    // cout << "c1 > c2: " << (c1 > c2) << endl;
    // cout << "c1 <= c2: " << (c1 <= c2) << endl;
    // cout << "c1 >= c2: " << (c1 >= c2) << endl;

    // cout << "c1 to string: " << c1.to_string() << endl;
    // cout << "c2 to string: " << c2.to_string() << endl;

    // Checking the Node class
    Node<int> node1(5);
    Node<int> node2(6);

    cout << "node1: " << node1.get_value() << endl;
    cout << "node2: " << node2.get_value() << endl;

    node1.add_child(&node2);

    cout << "node1 children: " << node1.get_childrens().size() << endl;

    node1.delete_children();

    cout << "node1 children: " << node1.get_childrens().size() << endl;

    cout << "To string: " << node1.to_string() << endl;

    return 0;
}