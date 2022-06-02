#include "function.h"
#include <cmath>
#include <iostream>

Function::Function()
{

}

double Function::GetValue(const double prev_value, Point3D first, Point3D second)
{
    double a = -1 * prev_value * _k / pow(norm(first, second), 3);
    return a;
}

double Function::norm(Point3D first, Point3D second) {
    double add = sqrt(pow((first.GetX() - second.GetX()), 2)
                      + pow((first.GetY() - second.GetY()), 2)
                      + pow((first.GetZ() - second.GetZ()), 2));
    return add;
}
