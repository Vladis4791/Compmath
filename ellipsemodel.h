#pragma once

#include <vector>
#include <cmath>

class EllipseModel
{
public:
    EllipseModel(double A, double B, double C, double D, double E, double year);

    std::vector<std::vector<double>> getPoints();
    double getBigAxis();
    double getBlackHoleMass();

private:
    const double step_value = 1000;
    double step;

    double A, B, C, D, E;
    double _T;
    double _blackHoleMass;
    double _bigAxis;
    double x_left, x_right;
    std::vector<std::vector<double>> points;

    void calcParams();
};
