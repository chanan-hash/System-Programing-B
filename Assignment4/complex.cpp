#include "complex.hpp"

// initial list of the complex number
Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

// Getters
double Complex::get_real() const { return real; }
double Complex::get_imaginary() const { return imaginary; }

// Checks if two complex numbers are equal.
bool Complex::operator==(const Complex &other) const
{
    return real == other.real && imaginary == other.imaginary;
}

// String representation of the complex number
string Complex::to_string() const
{
    std::ostringstream oss;
    if (real == 0 && imaginary == 0)
    {
        oss << "0";
    }
    else if (real == 0)
    {
        oss << "i" << imaginary;
    }
    else if (imaginary == 0)
    {
        oss << real;
    }
    else
    {
        oss << real << (imaginary > 0 ? "+i" : "-i") << abs(imaginary);
    }
    return oss.str();
}

// comparison operators
bool Complex::operator<(const Complex &other)
{
    return sqrt(pow(real, 2) + pow(imaginary, 2)) < sqrt(pow(other.real, 2) + pow(other.imaginary, 2));
}

bool Complex::operator>(const Complex &other)
{
    return sqrt(pow(real, 2) + pow(imaginary, 2)) > sqrt(pow(other.real, 2) + pow(other.imaginary, 2));
}

bool Complex::operator<=(const Complex &other)
{
    return !(*this > other);
}
bool Complex::operator>=(const Complex &other)
{
    return !(*this < other);
}

bool Complex::operator!=(const Complex &other)
{
    return !(*this == other);
}

// Overloads the << operator to print the complex number.
ostream &operator<<(ostream &os, const Complex &complex)
{
    os << complex.to_string();
    return os;
}

// Function to convert a complex number to a string
string cmpx_to_str(const Complex &complex)
{
    return complex.to_string();
}
