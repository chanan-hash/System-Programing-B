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

    CHECK_FALSE(c1 == c2);
    CHECK(c1 != c2);
    CHECK_FALSE(c1 < c2);
    CHECK_FALSE(c1 > c2);
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
        CHECK(tree_to_heap == "9 8 7 6 5 ");
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

// testing the 4-tree with complex numbers
TEST_CASE("Checking 4-tree with complex numbers")
{
    Node<Complex> node_cmpx1(Complex(1, 2));
    Node<Complex> node_cmpx2(Complex(1, -2));
    Node<Complex> node_cmpx3(Complex(3, 4));
    Node<Complex> node_cmpx4(Complex(5, 6));
    Node<Complex> node_cmpx5(Complex(7, 8));
    Node<Complex> node_cmpx6(Complex(9, 10));
    Node<Complex> node_cmpx7(Complex(11, -12));
    Node<Complex> node_cmpx8(Complex(13, 14));
    Node<Complex> node_cmpx9(Complex(15, 16));

    Tree<Complex, 4> tree_cmpx;
    tree_cmpx.add_root(&node_cmpx1);
    tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx2);
    tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx3);
    tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx4);
    tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx5);
    tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx6);
    tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx7);
    tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx8);
    tree_cmpx.add_sub_node(&node_cmpx2, &node_cmpx9);

    // checking the BFS
    SUBCASE("Checking BFS")
    {
        string BFS = "";
        for (auto it = tree_cmpx.begin_BFS(); it != tree_cmpx.end_BFS(); ++it)
        {
            BFS += (it)->get_value().to_string() + " ";
        }
        CHECK(BFS == "1+i2 1-i2 3+i4 5+i6 7+i8 9+i10 11-i12 13+i14 15+i16 ");
    }

    // checking the DFS
    SUBCASE("Checking DFS")
    {
        string DFS = "";
        for (auto it = tree_cmpx.begin_DFS(); it != tree_cmpx.end_DFS(); ++it)
        {
            DFS += (it)->get_value().to_string() + " ";
        }
        CHECK(DFS == "1+i2 1-i2 9+i10 11-i12 13+i14 15+i16 3+i4 5+i6 7+i8 ");

        // checking the Pre order
        string pre_order = "";
        for (auto it = tree_cmpx.begin_pre_order(); it != tree_cmpx.end_pre_order(); ++it)
        {
            pre_order += (it)->get_value().to_string() + " ";
        }
        CHECK(pre_order == "1+i2 1-i2 9+i10 11-i12 13+i14 15+i16 3+i4 5+i6 7+i8 ");
        CHECK(pre_order == DFS);
    }
    // checking the In order
    SUBCASE("Checking In order")
    {
        string in_order = "";
        for (auto it = tree_cmpx.begin_in_order(); it != tree_cmpx.end_in_order(); ++it)
        {
            in_order += (it)->get_value().to_string() + " ";
        }
        CHECK(in_order == "1+i2 1-i2 9+i10 11-i12 13+i14 15+i16 3+i4 5+i6 7+i8 ");
    }

    // checking the Post order
    SUBCASE("Checking Post order")
    {
        string post_order = "";
        for (auto it = tree_cmpx.begin_post_order(); it != tree_cmpx.end_post_order(); ++it)
        {
            post_order += (it)->get_value().to_string() + " ";
        }
        CHECK(post_order == "1+i2 1-i2 9+i10 11-i12 13+i14 15+i16 3+i4 5+i6 7+i8 ");
    }

    // checking the Tree to Heap
    SUBCASE("Checking Tree to Heap")
    {
        string tree_to_heap = "";
        for (auto it = tree_cmpx.begin_TreeToHeap(); it != tree_cmpx.end_TreeToHeap(); ++it)
        {
            tree_to_heap += (it)->get_value().to_string() + " ";
        }
        CHECK(tree_to_heap == "11-i12 1+i2 1-i2 3+i4 5+i6 7+i8 9+i10 13+i14 15+i16 ");
    }

    SUBCASE("Adding a child to a full parent")
    {
        Node<Complex> node_cmpx10(Complex(17, 18));
        CHECK_THROWS(tree_cmpx.add_sub_node(&node_cmpx1, &node_cmpx10));
    }
}