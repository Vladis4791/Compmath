#include "chart.h"
#include <QScatterSeries>
#include <QFont>

Chart::Chart(QWidget* widget, QString name)
{
    _chart = new QChart;
    _chartview = new QChartView(_chart);
    _layout = new QHBoxLayout;

    _axisX = new QValueAxis;
    _axisY = new QValueAxis;

    _axisX->setRange(-0.3, 0.1);
    _axisX-> setLabelFormat ("%f");
    _axisX-> setGridLineVisible (true);
    _axisX-> setMinorTickCount (1);
    _axisX-> setTitleText ("R.A");


    _axisY->setRange(-0.2, 0.2);
    _axisY->setLabelFormat("%f");
    _axisY->setGridLineVisible(true);
    _axisY->setTitleText("Dec.");

    _chart->addAxis (_axisX, Qt :: AlignBottom);
    _chart->addAxis (_axisY, Qt :: AlignLeft);
    _chart->axisX()->setReverse(true);


    //_chart->legend () -> hide ();

    _layout->removeWidget(_chartview);
    _layout->addWidget(_chartview);

    widget->setLayout(_layout);
}

Chart::~Chart()
{
    delete _axisX;
    delete _axisY;
    delete _chart;
    delete _chartview;
    delete _layout;
}

void Chart::addSeries(std::vector<std::vector<double>> points, QColor color, QString name)
{
    QSplineSeries *series = new QSplineSeries();
    series->setPen (QPen(color, 1, Qt::SolidLine));
    series->setName(name);

    for (size_t i = 0; i < points.size(); i++)
    {
        series->append(points[i][0], points[i][1]);
    }

    _chart->addSeries(series);

    _chart->setAxisX(_axisX, series);
    _chart->setAxisY(_axisY, series);
}

void Chart::addDiscreteSeries(std::vector<std::vector<double>> points, QColor color, QString name)
{
    QScatterSeries *series = new QScatterSeries();
    series->setName(name);
    series->setPen(QPen(color, 1, Qt::SolidLine));
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(3.0);

    for (size_t i = 0; i < points.size(); i++)
    {
        series->append(points[i][0], points[i][1]);
    }

    _chart->addSeries(series);

    _chart->setAxisX(_axisX, series);
    _chart->setAxisY(_axisY, series);
}
