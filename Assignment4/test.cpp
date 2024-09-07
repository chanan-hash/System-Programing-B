// Authors: Chanan helman
// chananhelman@gmail.com

#include "doctest.h"
#include "complex.hpp"
#include "Tree.hpp"

using namespace std;

// Test for complex + comparison operators for them + to string
TEST_CASE("Testing the complex class")
{
    Complex c1(1, 2);
    Complex c2(1, -2);

    CHECK(c1 == c2);
    CHECK(c1 != c2);
    CHECK(c1 < c2);
    CHECK(c1 > c2);
    CHECK(c1 <= c2);
    CHECK(c1 >= c2);
    CHECK(c1.to_string() == "1+i2");
    CHECK(c2.to_string() == "1-i2");
}

TEST_CASE("Testing the Node class")
{
    Node<int> node1(5);
    Node<int> node2(6);

    CHECK(node1.get_value() == 5);
    CHECK(node2.get_value() == 6);

    node1.add_child(&node2);

    CHECK(node1.get_childrens().size() == 1);

    node1.delete_children();

    CHECK(node1.get_childrens().size() == 0);

    CHECK(node1.to_string() == "5");
}

// Test for the tree according to the main
// testing the binary tree with integers

TEST_CASE("Checking binary INT tree")
{
    // creating nodes
    Node<int> node1(5);
    Node<int> node2(6);
    Node<int> node3(7);
    Node<int> node4(8);
    Node<int> node5(9);

    // creating the tree
    Tree<int> tree;
    tree.add_root(&node1);
    tree.add_sub_node(&node1, &node2);
    tree.add_sub_node(&node1, &node3);
    tree.add_sub_node(&node2, &node4);
    tree.add_sub_node(&node2, &node5);

    // checking the DFS
    SUBCASE("Checking DFS")
    {
        string DFS = "";
        for (auto it = tree.begin_DFS(); it != tree.end_DFS(); ++it)
        {
            DFS += to_string((it)->get_value()) + " ";
        }
        CHECK(DFS == "5 6 8 9 7 ");
    }

    // checking the BFS
    SUBCASE("Checking BFS")
    {
        string BFS = "";
        for (auto it = tree.begin_BFS(); it != tree.end_BFS(); ++it)
        {
            BFS += to_string((it)->get_value()) + " ";
        }
        CHECK(BFS == "5 6 7 8 9 ");
    }

    // checking the Pre order
    SUBCASE("Checking Pre order")
    {
        string pre_order = "";
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
        {
            pre_order += to_string((it)->get_value()) + " ";
        }
        CHECK(pre_order == "5 6 8 9 7 ");
    }

    // checking the In order
    SUBCASE("Checking In order")
    {
        string in_order = "";
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
        {
            in_order += to_string((it)->get_value()) + " ";
        }
        CHECK(in_order == "8 6 9 5 7 ");
    }

    // checking the Post order
    SUBCASE("Checking Post order")
    {
        string post_order = "";
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
        {
            post_order += to_string((it)->get_value()) + " ";
        }
        CHECK(post_order == "8 9 6 7 5 ");
    }

    // checking the Tree to Heap
    SUBCASE("Checking Tree to Heap")
    {
        string tree_to_heap = "";
        for (auto it = tree.begin_TreeToHeap(); it != tree.end_TreeToHeap(); ++it)
        {
            tree_to_heap += to_string((it)->get_value()) + " ";
        }
        CHECK(tree_to_heap == "5 6 7 8 9 ");
    }

    SUBCASE("Adding a child to a full parent")
    {
        Node<int> node6(10);
        CHECK_THROWS(tree.add_sub_node(&node1, &node6));
    }
}

// testing the binary tree with complex numbers
// Checking an empty tree, should not throw an exception, and BFS should be empty and DFS scan should be empty

TEST_CASE("empty tree")
{
    Tree<int, 3> tree;
    CHECK_NOTHROW(tree.begin_BFS());
    CHECK_NOTHROW(tree.begin_DFS());
    string BFS = "";
    for (auto it = tree.begin_BFS(); it != tree.end_BFS(); ++it)
    {
        BFS += to_string((it)->get_value()) + " ";
    }
    CHECK(BFS == "");
    string DFS = "";
    for (auto it = tree.begin_DFS(); it != tree.end_DFS(); ++it)
    {
        DFS += to_string((it)->get_value()) + " ";
    }
    CHECK(DFS == "");
}