#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// This is the class for the complex numbers

class Complex
{
private: // the definition of the complex number
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary);

    // Getters
    double get_real() const;
    double get_imaginary() const;

    /**
     * Checks if two complex numbers are equal.
     * Two complex numbers are equal if their real and imaginary parts are equal.
     * @param other The other complex number to compare with.
     */
    bool operator==(const Complex &other) const;

    // String representation of the complex number
    string to_string() const;

    // comparison operators
    bool operator<(const Complex &other);
    bool operator>(const Complex &other);
    bool operator<=(const Complex &other);
    bool operator>=(const Complex &other);
    bool operator!=(const Complex &other);

    /**
     * Overloads the << operator to print the complex number.
     */
    friend ostream &operator<<(ostream &os, const Complex &complex);
};

// Function to convert a complex number to a string
string cmpx_to_str(const Complex &complex);