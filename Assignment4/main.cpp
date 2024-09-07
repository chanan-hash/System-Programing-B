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
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping In order:" << endl;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Post order:" << endl;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Tree to Heap:" << endl;
    for (auto it = tree.begin_TreeToHeap(); it != tree.end_TreeToHeap(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << tree << endl;

    // checking the generic tree for complex numbers

    Node<Complex> node_cmpx1(Complex(1, 2));
    Node<Complex> node_cmpx2(Complex(1, -2));
    Node<Complex> node_cmpx3(Complex(3, 4));
    Node<Complex> node_cmpx4(Complex(5, 6));
    Node<Complex> node_cmpx5(Complex(7, 8));
    Tree<Complex> tree_cmpx;

    tree_cmpx.add_root(&node_cmpx1);
    tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx2);
    tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx3);
    tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx4);
    tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx5);

    cout << "Looping BFS for complex numbers:" << endl;
    for (auto it = tree_cmpx.begin_BFS(); it != tree_cmpx.end_BFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping DFS for complex numbers:" << endl;
    for (auto it = tree_cmpx.begin_DFS(); it != tree_cmpx.end_DFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Pre order for complex numbers:" << endl;
    for (auto it = tree_cmpx.begin_pre_order(); it != tree_cmpx.end_pre_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping In order for complex numbers:" << endl;
    for (auto it = tree_cmpx.begin_in_order(); it != tree_cmpx.end_in_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Post order for complex numbers:" << endl;
    for (auto it = tree_cmpx.begin_post_order(); it != tree_cmpx.end_post_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Tree to Heap for complex numbers:" << endl;
    for (auto it = tree_cmpx.begin_TreeToHeap(); it != tree_cmpx.end_TreeToHeap(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;


    // checking the generic tree for strings
    // checking the generic tree for doubles
    Node<double> node_double1(1.1);
    Node<double> node_double2(2.2);
    Node<double> node_double3(3.3);
    Node<double> node_double4(4.4);
    Node<double> node_double5(5.5);
    Tree<double> tree_double;

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
    for (auto it = tree_double.begin_pre_order(); it != tree_double.end_pre_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping In order for doubles:" << endl;
    for (auto it = tree_double.begin_in_order(); it != tree_double.end_in_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Post order for doubles:" << endl;
    for (auto it = tree_double.begin_post_order(); it != tree_double.end_post_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Tree to Heap for doubles:" << endl;
    for (auto it = tree_double.begin_TreeToHeap(); it != tree_double.end_TreeToHeap(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    // checking the generic tree for char

    // checking the generic tree for int but has 4 children each node
    Node<int> node_int1(1);
    Node<int> node_int2(2);
    Node<int> node_int3(3);
    Node<int> node_int4(4);
    Node<int> node_int5(5);
    Node<int> node_int6(6);
    Node<int> node_int7(7);
    Node<int> node_int8(8);
    Node<int> node_int9(9);

    Tree<int, 4> tree_int; // declearing the tree after the nodes

    tree_int.add_root(&node_int1);
    tree_int.add_sub_node(&node_int1, &node_int2);
    tree_int.add_sub_node(&node_int1, &node_int3);
    tree_int.add_sub_node(&node_int1, &node_int4);
    tree_int.add_sub_node(&node_int1, &node_int5);
    tree_int.add_sub_node(&node_int2, &node_int6);
    tree_int.add_sub_node(&node_int2, &node_int7);
    tree_int.add_sub_node(&node_int2, &node_int8);
    tree_int.add_sub_node(&node_int2, &node_int9);

    // The tree should look like this:
    //        1
    //     /  |  |  \.
    //    2   3  4   5
    //   /|\.
    //  6 7 8 9

    cout << "Looping BFS for int with 4 children:" << endl;
    for (auto it = tree_int.begin_BFS(); it != tree_int.end_BFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping DFS for int with 4 children:" << endl;
    for (auto it = tree_int.begin_DFS(); it != tree_int.end_DFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Pre order for int with 4 children:" << endl;
    for (auto it = tree_int.begin_pre_order(); it != tree_int.end_pre_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping In order for int with 4 children:" << endl;
    for (auto it = tree_int.begin_in_order(); it != tree_int.end_in_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }

    cout << endl;

    cout << "Looping Post order for int with 4 children:" << endl;
    for (auto it = tree_int.begin_post_order(); it != tree_int.end_post_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Tree to Heap for int with 4 children:" << endl;
    for (auto it = tree_int.begin_TreeToHeap(); it != tree_int.end_TreeToHeap(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    // checking the generic tree for string but has 3 children each node
    Node<string> node_str1("1");
    Node<string> node_str2("2");
    Node<string> node_str3("3");
    Node<string> node_str4("4");
    Node<string> node_str5("5");
    Node<string> node_str6("6");
    Node<string> node_str7("7");
    Node<string> node_str8("8");
    Node<string> node_str9("9");
    Node<string> node_str10("10");

    Tree<string, 3> tree_str; // declearing the tree after the nodes

    tree_str.add_root(&node_str1);
    tree_str.add_sub_node(&node_str1, &node_str2);
    tree_str.add_sub_node(&node_str1, &node_str3);
    tree_str.add_sub_node(&node_str1, &node_str4);
    // tree_str.add_sub_node(&node_str1, &node_str5); // should throw an exception
    tree_str.add_sub_node(&node_str2, &node_str5);
    tree_str.add_sub_node(&node_str2, &node_str6);
    tree_str.add_sub_node(&node_str2, &node_str7);

    tree_str.add_sub_node(&node_str4, &node_str8);
    tree_str.add_sub_node(&node_str4, &node_str9);
    tree_str.add_sub_node(&node_str4, &node_str10);

    // The tree should look like this:
    //        1
    //     /  |  |
    //    2   3  4
    //   /|\.   /|\.
    //  5 6 7   8 9 10

    cout << "Looping BFS for string with 3 children:" << endl;
    for (auto it = tree_str.begin_BFS(); it != tree_str.end_BFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping DFS for string with 3 children:" << endl;
    for (auto it = tree_str.begin_DFS(); it != tree_str.end_DFS(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Pre order for string with 3 children:" << endl;
    for (auto it = tree_str.begin_pre_order(); it != tree_str.end_pre_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping In order for string with 3 children:" << endl;
    for (auto it = tree_str.begin_in_order(); it != tree_str.end_in_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }

    cout << endl;

    cout << "Looping Post order for string with 3 children:" << endl;
    for (auto it = tree_str.begin_post_order(); it != tree_str.end_post_order(); ++it)
    {
        cout << (it)->get_value() << " ";
    }
    cout << endl;

    cout << "Looping Tree to Heap for string with 3 children:" << endl;
    for (auto it = tree_str.begin_TreeToHeap(); it != tree_str.end_TreeToHeap(); ++it)
    {
        cout << (it)->get_value() << " ";
    }

    cout << endl;

    return 0;
}