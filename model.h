#pragma once

#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chart.h"
#include "ellipsemodel.h"
#include <iostream>
#include <matrix.hpp>
#include <fstream>

class Model
{
public:
    Model(std::string fileName);
    Model(std::vector<double> x, std::vector<double> y);

    double A, B, C, D, E;
    std::vector<std::vector<double>> points;
private:
    std::vector<double> x, y;

    void Calc();
};
