#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct lorentzStruct
{
    double lorentzBarred[4];
};

double standardInterval(double t, double x, double y, double z)
{
    double standard_interval;

    standard_interval = (x*x + y*y + z*z) - (t*t);

    return standard_interval;
}

struct lorentzStruct lorentzTransform (double frame_velocity, int direction, double time, double x, double y, double z)
{
    struct lorentzStruct output;

    switch (direction)
    {
        case 1:
           output.lorentzBarred[0] = (time/sqrt(1-frame_velocity*frame_velocity))-((frame_velocity*x)/sqrt(1-frame_velocity*frame_velocity));
           output.lorentzBarred[1] = (-frame_velocity * time) / sqrt(1-frame_velocity*frame_velocity) + (x/sqrt(1-frame_velocity*frame_velocity));
           output.lorentzBarred[2] = y;
           output.lorentzBarred[3] = z;
           break;
        case 2:
           output.lorentzBarred[0] = (time/sqrt(1-frame_velocity*frame_velocity))-((frame_velocity*y)/sqrt(1-frame_velocity*frame_velocity));
           output.lorentzBarred[1] = x;
           output.lorentzBarred[2] = (-frame_velocity * time) / sqrt(1-frame_velocity*frame_velocity) + (y/sqrt(1-frame_velocity*frame_velocity));
           output.lorentzBarred[3] = z;
           break;
        case 3:
           output.lorentzBarred[0] = (time/sqrt(1-frame_velocity*frame_velocity))-((frame_velocity*z)/sqrt(1-frame_velocity*frame_velocity));
           output.lorentzBarred[1] = x;
           output.lorentzBarred[2] = y;
           output.lorentzBarred[3] = (-frame_velocity * time) / sqrt(1-frame_velocity*frame_velocity) + (z/sqrt(1-frame_velocity*frame_velocity));
           break;
    }

    return output;
}

double velocityAddition (double particle_velocity, double frame_velocity)
{
    double output_velocity;

    output_velocity = (particle_velocity + frame_velocity)/(1+particle_velocity*frame_velocity);

    return output_velocity;
}
