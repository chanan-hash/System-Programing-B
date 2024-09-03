// Authors: Chanan helman
// chananhelman@gmail.com

#include <iostream>
#include <string>
#include <vector>
#include "complex.hpp"
#include "Node.hpp"
// #include "Tree.hpp"

using namespace std;

int main()
{
    // Checking the complex class
    Complex c1(1, 2);
    Complex c2(1, -2);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout << "c1 <= c2: " << (c1 <= c2) << endl;
    cout << "c1 >= c2: " << (c1 >= c2) << endl;

    cout << "c1 to string: " << c1.to_string() << endl;
    cout << "c2 to string: " << c2.to_string() << endl;

    // Checking the Node class
    // Node<int> node1(5);
    // Node<int> node2(6);

    // cout << "node1: " << node1.get_value() << endl;
    // cout << "node2: " << node2.get_value() << endl;

    // node1.add_child(&node2);

    // cout << "node1 children: " << node1.get_childrens().size() << endl;

    // node1.delete_children();

    // cout << "node1 children: " << node1.get_childrens().size() << endl;

    // cout << "To string: " << node1.to_string() << endl;

    // checking the tree class, and the iterators

    // Tree<int> tree;

    // Node<int> root(1);
    // Node<int> child1(2);
    // Node<int> child2(3);
    // Node<int> child3(4);

    // tree.add_root(&root);
    // tree.add_sub_node(&root, &child1);
    // tree.add_sub_node(&root, &child2);
    // tree.add_sub_node(&root, &child3);

    // // need to check the iterators
    
    // for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;
    

    return 0;
}