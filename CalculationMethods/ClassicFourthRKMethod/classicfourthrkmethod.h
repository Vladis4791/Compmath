#pragma once

#include "../method.h"
#include "point3d.h"

class ClassicFourthRKMethod : public Method
{
public:
    ClassicFourthRKMethod(double deltaT, Function* function);

    virtual double GetValue(const double prev_count, const double prev_speed) override;
    virtual double GetSpeed(const double prev_speed, const double prev_x,
                            const Point3D first, const Point3D second) override;

private:
    double k_1(double prev_count, Point3D first, Point3D second);
    double k_2(double prev_count, Point3D first, Point3D second);
    double k_3(double prev_count, Point3D first, Point3D second);
    double k_4(double prev_count, Point3D first, Point3D second);
};
