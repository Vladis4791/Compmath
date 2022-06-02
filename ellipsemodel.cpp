#include "ellipsemodel.h"
#include <cmath>

//EllipseModel::EllipseModel(std::vector<double> params)
//    :EllipseModel(params[0], params[1], params[2], params[3], params[4])
//{

//}

EllipseModel::EllipseModel(double A, double B, double C, double D, double E, double year)
    : A(A)
    , B(B)
    , C(C)
    , D(D)
    , E(E)
    , _T(year)
{
    double a = A*A - 4*B; double b = 2*A*D - 4*B*C; double c = D*D-4*B*E;
    double discriminant = b*b - 4*a*c;
    double x1 = (-b-std::sqrt(discriminant)) / (2 * a);
    double x2 = (-b+std::sqrt(discriminant)) / (2 * a);
    x_left = std::min(x1, x2);
    x_right = std::max(x1, x2);

    step = (x_right - x_left) / step_value;

    std::vector<std::vector<double>> bigger;
    std::vector<std::vector<double>> lower;
    for(double x = x_left; x - x_right <= 0; x += step)
    {
        a = B; b = A*x+D; c = x*x+C*x+E;
        discriminant = b*b - 4*a*c;
        if (discriminant < 0 || a == 0) continue;
        double y1 = (-b-std::sqrt(discriminant)) / (2 * a);
        double y2 = (-b+std::sqrt(discriminant)) / (2 * a);

        bigger.push_back({x, std::max(y1, y2)});
        lower.push_back({x, std::min(y1, y2)});
    }

    for(size_t i = 0; i < lower.size(); i++) {
        points.push_back(lower[i]);
    }
    for(int i = bigger.size() - 1; i >= 0; i--) {
        points.push_back(bigger[i]);
    }
    points.push_back(lower[0]);

    calcParams();
}

std::vector<std::vector<double>> EllipseModel::getPoints() { return points; }
double EllipseModel::getBigAxis() { return _bigAxis; }
double EllipseModel::getBlackHoleMass() { return _blackHoleMass; }

void EllipseModel::calcParams()
{
    double delta = A*A-4*B;
    double nom = 2 * (A*C*D - B*C*C - D*D + 4*B*E - A*A*E);
    double s = std::sqrt(A*A + std::pow(1-B, 2));

    double a_prime = std::sqrt(nom / (delta*(B-s+1)));
    double b_prime = std::sqrt(nom / (delta*(B+s+1)));

    _bigAxis = std::max(a_prime, b_prime);

    //Вычисление массы СЧД
    double PI = 4*atan(1.);
    double bigAxixInMetrs = sin(_bigAxis) * PI / (180 * 3600) * 8930 * 3.086e+16;
    _blackHoleMass = (pow(bigAxixInMetrs, 3) * 4 * pow(PI, 2))
            / (pow(_T * 365 * 24 * 60 * 60, 2) * 6.6743 * pow(10, -11));
    _blackHoleMass /= 1.988 * pow (10, 36);
}


