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

    cout << "Looping Post order:" << endl;
    for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it) {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    // cout<< "Looping Tree to Heap:" << endl;
    // for (auto it = tree.begin_TreeToHeap(); it != tree.end_TreeToHeap(); ++it)
    // {
    //     cout << (it)->get_value() << " ";
    // }

    // checking the generic tree for complex numbers

    // Tree<Complex> tree_cmpx;
    // Node<Complex> node_cmpx1(Complex(1, 2));
    // Node<Complex> node_cmpx2(Complex(1, -2));
    // Node<Complex> node_cmpx3(Complex(3, 4));
    // Node<Complex> node_cmpx4(Complex(5, 6));
    // Node<Complex> node_cmpx5(Complex(7, 8));

    // tree_cmpx.add_root(&node_cmpx1);
    // tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx2);
    // tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx3);
    // tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx4);
    // tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx5);

    // cout << "Looping BFS for complex numbers:" << endl;
    // for (auto it = tree_cmpx.begin_BFS(); it != tree_cmpx.end_BFS(); ++it)
    // {
    //     cout << (it)->get_value() << " ";
    // }
    // cout << endl;

    // cout << "Looping DFS for complex numbers:" << endl;
    // for (auto it = tree_cmpx.begin_DFS(); it != tree_cmpx.end_DFS(); ++it)
    // {
    //     cout << (it)->get_value() << " ";
    // }
    // cout << endl;

    // cout << "Looping Pre order for complex numbers:" << endl;
    // for (auto it = tree_cmpx.begin_preorder(); it != tree_cmpx.end_preorder(); ++it)
    // {
    //     cout << (it)->get_value() << " ";
    // }
    // cout << endl;

    // cout << "Looping In order for complex numbers:" << endl;
    // for (auto it = tree_cmpx.begin_inorder(); it != tree_cmpx.end_inorder(); ++it)
    // {
    //     cout << (it)->get_value() << " ";
    // }
    // cout << endl;

    // cout << "Looping Post order for complex numbers:" << endl;
    // for (auto it = tree_cmpx.begin_postorder(); it != tree_cmpx.end_postorder(); ++it)
    // {
    //     cout << (it)->get_value() << " ";
    // }
    // cout << endl;


    // checking the generic tree for strings
    // checking the generic tree for doubles
    Tree<double> tree_double;
    Node<double> node_double1(1.1);
    Node<double> node_double2(2.2);
    Node<double> node_double3(3.3);
    Node<double> node_double4(4.4);
    Node<double> node_double5(5.5);

    tree_double.add_root(&node_double1);
    tree_double.add_sub_node(&node_double1, &node_double2);
    tree_double.add_sub_node(&node_double1, &node_double3);
    tree_double.add_sub_node(&node_double2, &node_double4);
    tree_double.add_sub_node(&node_double2, &node_double5);

    cout << "Looping BFS for doubles:" << endl;
    for (auto it = tree_double.begin_BFS(); it != tree_double.end_BFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping DFS for doubles:" << endl;

    for (auto it = tree_double.begin_DFS(); it != tree_double.end_DFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }

    cout << endl;

    cout << "Looping Pre order for doubles:" << endl;
    for (auto it = tree_double.begin_preorder(); it != tree_double.end_preorder(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping In order for doubles:" << endl;
    for (auto it = tree_double.begin_inorder(); it != tree_double.end_inorder(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Post order for doubles:" << endl;
    for (auto it = tree_double.begin_postorder(); it != tree_double.end_postorder(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    


    // checking the generic tree for char


    // checking the generic tree for int but has 4 children each node

    return 0;
}