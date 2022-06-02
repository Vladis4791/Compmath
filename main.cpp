#include "mainwindow.h"

#include <QApplication>
#include <QGenericMatrix>
#include <matrix.hpp>
#include <fstream>
#include <sstream>
#include "CalculationMethods/ClassicFourthRKMethod/classicfourthrkmethod.h"
#include "Functions/function.h"
#include <iostream>
#include <fstream>

void iauS2c(double theta, double phi, double c[3])
{
   double cp;

   cp = cos(phi);
   c[0] = cos(theta) * cp;
   c[1] = sin(theta) * cp;
   c[2] = sin(phi);
}

void iauC2s(double p[3], double *theta, double *phi)
{
   double x, y, z, d2;

   x  = p[0];
   y  = p[1];
   z  = p[2];
   d2 = x*x + y*y;

   *theta = (d2 == 0.0) ? 0.0 : atan2(y, x);
   double add = sqrt(d2);
   double add_2 = atan2(z, add);
   *phi = (z == 0.0) ? 0.0 : add_2;
}

void iauS2pv(double theta, double phi, double r,
             double td, double pd, double rd,
             double pv[2][3])
{
   double st, ct, sp, cp, rcp, x, y, rpd, w;


   st = sin(theta);
   ct = cos(theta);
   sp = sin(phi);
   cp = cos(phi);
   rcp = r * cp;
   x = rcp * ct;
   y = rcp * st;
   rpd = r * pd;
   w = rpd*sp - cp*rd;

   pv[0][0] = x;
   pv[0][1] = y;
   pv[0][2] = r * sp;
   pv[1][0] = -y*td - w*ct;
   pv[1][1] =  x*td - w*st;
   pv[1][2] = rpd*cp + sp*rd;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
