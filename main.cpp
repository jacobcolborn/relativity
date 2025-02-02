#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double standardInterval(double t, double x, double y, double z)
{
    double standardInterval;

    standardInterval = (x*x + y*y + z*z) - (t*t);

    return standardInterval;
}

double lorentzTransform (double frameVelocity, int direction, double time, double x, double y, double z)
{
    double outputX;
    double outputT;

    switch (direction)
    {
        case 1:
           outputT = (time/sqrt(1-frameVelocity*frameVelocity))-((frameVelocity*x)/sqrt(1-frameVelocity*frameVelocity));
           outputX = (-frameVelocity * time) / sqrt(1-frameVelocity*frameVelocity) + (x/sqrt(1-frameVelocity*frameVelocity));
           cout << "t bar = " << outputT << endl;
           cout << "x bar = " << outputX << endl;
           cout << "y bar = " << y << endl;
           cout << "z bar = " << z << endl;
           break;
        case 2:
           outputT = (time/sqrt(1-frameVelocity*frameVelocity))-((frameVelocity*y)/sqrt(1-frameVelocity*frameVelocity));
           outputX = (-frameVelocity * time) / sqrt(1-frameVelocity*frameVelocity) + (y/sqrt(1-frameVelocity*frameVelocity));
           cout << "t bar = " << outputT << endl;
           cout << "x bar = " << x << endl;
           cout << "y bar = " << outputX << endl;
           cout << "z bar = " << z << endl;
           break;
        case 3:
           outputT = (time/sqrt(1-frameVelocity*frameVelocity))-((frameVelocity*z)/sqrt(1-frameVelocity*frameVelocity));
           outputX = (-frameVelocity * time) / sqrt(1-frameVelocity*frameVelocity) + (z/sqrt(1-frameVelocity*frameVelocity));
           cout << "t bar = " << outputT << endl;
           cout << "x bar = " << x << endl;
           cout << "y bar = " << y << endl;
           cout << "z bar = " << outputX << endl;
           break;
    }

    return 0;
}

double velocityAddition (double particleVelocity, double frameVelocity)
{
    double outputVelocity;

    outputVelocity = (particleVelocity + frameVelocity)/(1+particleVelocity*frameVelocity);

    return outputVelocity;
}


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

