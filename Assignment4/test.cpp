#include "doctest.h"
#include "complex.hpp"
#include "Node.hpp"

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

// Test for the tree 