#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex
{
private:
    double real;
    double image;

public:
    Complex(double m, double n);
    Complex(/* args */);
    ~Complex();
    Complex operator+(const Complex &another) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;
    Complex operator*(double) const;
    Complex operator~() const;
    friend Complex operator*(double, const Complex &another);
    friend std::ostream &operator<<(std::ostream &, const Complex &another);
    friend std ::istream &operator>>(std::istream &, Complex &another);
};

#endif