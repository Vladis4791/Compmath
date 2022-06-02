#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chart.h"
#include "ellipsemodel.h"
#include <iostream>
#include <matrix.hpp>
#include <fstream>
#include <model.h>
#include <massmnk.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1000, 800);

    Model S2("../data/S2.txt");
    Model S38("../data/S38.txt");
    Model S55("../data/S55.txt");

    EllipseModel* ellipseS2 = new EllipseModel(S2.A, S2.B, S2.C, S2.D, S2.E, 16.2);
    EllipseModel* ellipseS38 = new EllipseModel(S38.A, S38.B, S38.C, S38.D, S38.E, 19);
    EllipseModel* ellipseS55 = new EllipseModel(S55.A, S55.B, S55.C, S55.D, S55.E, 12);

    Chart* chart = new Chart(ui->widget, "Ellipse");

    chart->addSeries(ellipseS2->getPoints(), Qt::red, "Star S2");
    chart->addSeries(ellipseS38->getPoints(), Qt::blue, "Star S38");
    chart->addSeries(ellipseS55->getPoints(), Qt::green, "Star S55");

    chart->addDiscreteSeries(S2.points, Qt::red, "Star points S2");
    chart->addDiscreteSeries(S38.points, Qt::blue, "Star points S38");
    chart->addDiscreteSeries(S55.points, Qt::green, "Star points S55");

    double mass = (ellipseS2->getBlackHoleMass()
            + ellipseS38->getBlackHoleMass()
            + ellipseS55->getBlackHoleMass()) / 3;

    ui->label->setText("Среднее значение массы: " + QString::number(mass) + " * 10^6 масс Солнц");
}

MainWindow::~MainWindow()
{
    delete ui;
}

