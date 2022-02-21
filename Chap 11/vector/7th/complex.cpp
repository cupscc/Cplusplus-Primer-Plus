#include "complex.h"
Complex ::Complex(double m, double n)
{
    real = m;
    image = n;
}
Complex::Complex(/* args */)
{
    real = image = 0;
}

Complex::~Complex()
{
}

Complex Complex ::operator+(const Complex &another) const
{
    Complex res;
    res.image = image + another.image;
    res.real = real + another.real;
    return res;
}

Complex Complex ::operator-(const Complex &another) const
{
    Complex res;
    res.image = image - another.image;
    res.real = real - another.real;
    return res;
}
Complex Complex ::operator*(const Complex &another) const
{
    Complex res;
    res.real = real * another.real - image * another.image;
    res.image = real * another.image + image * another.real;
    return res;
}
Complex Complex ::operator*(double m) const
{
    return Complex(m * real, m * image);
}
Complex Complex ::operator~() const
{
    return Complex(real, -image);
}
// friend
Complex operator*(double m, const Complex &another)
{
    return Complex(m * another.real, m * another.image);
}
std::ostream &operator<<(std::ostream &os, const Complex &another)
{
    os << "(" << another.real << "," << another.image << ")";
    return os;
}
std::istream &operator>>(std::istream &is, Complex &another) //这里不能用const 修饰another了
{
    std::cout << "Real: ";
    is >> another.real;
    std::cout << "Image: ";
    is >> another.image;
    return is;
} //好像需要在头文件里也把参数声明进去啊 友元函数可以修改私有成员