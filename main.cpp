#include <iostream>
#include <cstdio>
#include <cmath>

#include "special.h"

using namespace std;

int main()
{
    double t, x, y, z, v, w;
    int path;
    double interval, velocity;

    cout << "Enter your time and position coordinates (t,x,y,z): " << endl;
    cin >> t;
    cin >> x;
    cin >> y;
    cin >> z;
    cout << "Enter the direction of travel for the primed frame (1,2,3): " << endl;
    cin >> path;
    cout << "Enter your primed frame velocity relative to your first frame: " << endl;
    cin >> v;
    cout << "Enter the velocity of your particle: " << endl;
    cin >> w;

    interval = standardInterval(t,x,y,z);

    lorentzTransform(v, path, t, x, y, z);

    velocity = velocityAddition(w, v);

    cout << "Your interval is " << interval << " ." << endl;
    cout << "The particle velocity in the other frame is " << velocity << endl;

    return 0;
}

