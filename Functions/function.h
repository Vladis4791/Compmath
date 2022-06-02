#pragma once
#include "point3d.h"
#include <cmath>

class Function
{
public:
    Function();

    double GetValue(const double prev_value, Point3D first, Point3D second);
    double norm(Point3D first, Point3D second);

private:
//    const double _G = 6.6743 * pow(10, -11);
    const double _G = 0.01720209895;
    const double _k = _G * _G * 4000000;
};
