#include "vector.h"
#include <cmath>
using std ::atan;
using std::atan2;
using std ::cos;
using std ::cout;
using std::sin;
using std::sqrt;
namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    Vector ::Vector()
    {
        x = y = ang = mag = 0;
        mode = RECT;
    }
    Vector ::Vector(double m, double n, Mode mymode)
    {
        mode = mymode;
        if (mymode == RECT)
        {
            x = m;
            y = n;
            set_mag();
            set_ang();
        }
        else if (mymode == POL)
        {
            mag = m;
            ang = n / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "unvalid input for the mode \n";
            mode = RECT;
        }
    }
    Vector ::~Vector()
    {
    }
    void Vector::reset(double m, double n, Mode mymode)
    {
        mode = mymode;
        if (mymode == RECT)
        {
            x = m;
            y = n;
            set_mag();
            set_ang();
        }
        else if (mymode == POL)
        {
            mag = m;
            ang = n / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "unvalid input for the mode \n";
            mode = RECT;
        }
    }
    void Vector::polar_mode()
    {
        mode = POL;
    }
    void Vector::rect_mode()
    {
        mode == RECT;
    }
    Vector Vector::operator+(const Vector &v) const
    {
        return Vector(v.x + x, v.y + y, RECT);
    }
    Vector Vector::operator-(const Vector &v) const
    {
        return Vector(x - v.x, y - v.y, RECT);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const
    {
        return Vector(x * n, y * n);
    }
    Vector operator*(double n, const Vector &a)
    {
        return Vector(n * a.x, n * a.y);
    }
    std::ostream &operator<<(std::ostream &os, const Vector &a)
    {
        if (a.mode == Vector::RECT)
        {
            os << "(x,y) = (" << a.x << "," << a.y << ")";
        }
        else if (a.mode == Vector::POL)
        {
            os << "(m,a) = (" << a.mag << "," << a.ang * Rad_to_deg << ")";
        }
        else
        {
            os << "unvalid mode\n";
        }
        return os;
    }
    void Vector ::set_x()
    {
        x = mag * cos(ang);
    }
    void Vector ::set_y()
    {
        y = mag * sin(ang);
    }
    void Vector ::set_ang()
    {
        if (x == 0.0 && y == 0.0)
        {
            ang == 0.0;
        }
        else
            ang = atan2(y, x);
    }
    void Vector ::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }
}
