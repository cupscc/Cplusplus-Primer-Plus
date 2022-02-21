#include "vector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
int main()
{
    using namespace std;
    using VECTOR ::Vector;
    srand(time(0)); // time() gets the current time
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter the target distance (enter q to exit):";
    ofstream f1;
    f1.open("randwalk.txt");

    if (cin >> target) //
    {
        cout << "Enter step length :";
        if (!(cin >> dstep))
        {
            // break;
        }
        else
        {
            while (result.magval() < target)
            {
                f1 << steps << " : (x,y) = (" << result.xval() << "," << result.yval() << ")\n";
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            f1 << "After " << steps << " steps ,the man came to the place with the location \n";
            f1 << result << endl;
            result.polar_mode();
            f1 << "or\n"
               << result << endl;
            f1 << "Average outward distance per step = " << result.magval() / steps << endl;
            steps = 0;
            result.reset(0.0, 0.0);
            // cout << "Enter target distance(q to exit):";
        }
    }
    /*cout << "Bye\n";
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }*/
    return 0;
}