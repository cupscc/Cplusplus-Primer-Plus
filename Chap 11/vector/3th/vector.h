#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
namespace VECTOR
{
    class Vector
    {

    public:
        enum Mode
        {
            RECT,
            POL
        };
        Vector();
        Vector(double, double, Mode mode = RECT);
        ~Vector();
        void reset(double, double, Mode mode = RECT);
        double xval() const { return x; };
        double yval() const { return y; };
        double magval() const { return mag; };
        double angval() const { return ang; };
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector &) const;
        Vector operator-(const Vector &) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, const Vector &a);

    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_x();
        void set_y();
        void set_mag();
        void set_ang();
    };
}
#endif // VECTOR_H endif 后面不需要加东西