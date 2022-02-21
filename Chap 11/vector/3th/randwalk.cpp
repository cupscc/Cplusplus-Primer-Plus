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
    cout << "Enter the target times (enter q to exit):";
    ofstream f1;
    f1.open("randwalk.txt");
    unsigned int times;
    if (cin >> times && times > 0)
    {
        cout << "Enter the target distance (enter q to exit):";
        if (!(cin >> target))
        {
            // break;
        }
        else
        {
            cout << "Enter step length :";
            if (!(cin >> dstep))
            {
                // break;
            }
            else
            {
                unsigned int maxtimes, mintimes, average, left_times;
                maxtimes = mintimes = average = 0;
                mintimes = 2 ^ 32;
                left_times = times;
                while (left_times > 0) //
                {

                    while (result.magval() < target)
                    {
                        // f1 << steps << " : (x,y) = (" << result.xval() << "," << result.yval() << ")\n";
                        direction = rand() % 360;
                        step.reset(dstep, direction, Vector::POL);
                        result = result + step;
                        steps++;
                    }
                    if (maxtimes < steps)
                    {
                        maxtimes = steps;
                    }
                    if (mintimes > steps)
                    {
                        mintimes = steps;
                    }
                    average += steps;
                    /*f1 << "After " << steps << " steps ,the man came to the place with the location \n";
                    f1 << result << endl;
                    result.polar_mode();
                    f1 << "or\n"
                       << result << endl;
                    f1 << "Average outward distance per step = " << result.magval() / steps << endl;*/
                    steps = 0;
                    result.reset(0.0, 0.0);
                    // cout << "Enter target distance(q to exit):";
                    left_times--;
                }
                f1 << "maxtimes is : " << maxtimes << " minitimes is : " << mintimes << " average time is : " << (average / times);
            }
        }
        /*cout << "Bye\n";
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }*/
    }
    return 0;
}