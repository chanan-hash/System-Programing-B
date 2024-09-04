// Authors: Chanan helman
// chananhelman@gmail.com

#include <iostream>
#include <string>
#include <vector>

#include "Tree.hpp"
#include "complex.hpp"

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
    Node<int> node1(5);
    Node<int> node2(6);
    Node<int> node3(7);
    Node<int> node4(8);
    Node<int> node5(9);

    cout << "node1: " << node1.get_value() << endl;
    cout << "node2: " << node2.get_value() << endl;

    node1.add_child(&node2);

    cout << "node1 children: " << node1.get_childrens().size() << endl;

    node1.delete_children();

    cout << "node1 children: " << node1.get_childrens().size() << endl;

    cout << "To string: " << node1.to_string() << endl;

    Tree<int> tree;
    tree.add_root(&node1);
    tree.add_sub_node(&node1, &node2);
    tree.add_sub_node(&node1, &node3);
    // tree.add_sub_node(&node1, &node4); should throw an exception
    tree.add_sub_node(&node2, &node4);
    tree.add_sub_node(&node2, &node5);

    /**
     *        5
     *       / \
     *     6   7
     *   / \
     * 8   9
     */

    // Looping through the tree using iterators
    cout << "Looping DFS:" << endl;
    for (auto it = tree.begin_DFS(); it != tree.end_DFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping BFS:" << endl;
    for (auto it = tree.begin_BFS(); it != tree.end_BFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Pre order:" << endl;
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping In order:" << endl;
    for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    // cout << "Looping Post order:" << endl;
    // for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it) {
    //     cout << (it)->get_value() << " ";
    // }
    // cout << endl;

    return 0;
}