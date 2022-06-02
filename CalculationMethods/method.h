#pragma once
#include "Functions/function.h"


class Method
{
public:
    Method(double deltaT, Function* function);

    virtual double GetValue(const double prev_count, const double prev_speed) = 0;
    virtual double GetSpeed(const double prev_speed, const double prev_x,
                            const Point3D first, const Point3D second) = 0;

protected:
    double _deltaT;
    Function* _function;
};
