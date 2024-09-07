#include "complex.hpp"

// initial list of the complex number
Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

// Getters
double Complex::get_real() const { return real; }
double Complex::get_imaginary() const { return imaginary; }

// Checks if two complex numbers are equal.
bool Complex::operator==(const Complex &other) const
{
    return (real == other.real) && (imaginary == other.imaginary);
}
bool Complex::operator!=(const Complex &other) const
{
    return !(*this == other);
}

// comparison operators
bool Complex::operator<(const Complex &other) const
{
    return real > other.real && imaginary > other.imaginary;
}

// for some reason, the operator> is not working as expected other < *this
// TODO - check why
bool Complex::operator>(const Complex &other) const
{
    return other < *this;
}

bool Complex::operator<=(const Complex &other) const
{
    return !(*this > other);
}
bool Complex::operator>=(const Complex &other) const
{
    return !(*this < other);
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
