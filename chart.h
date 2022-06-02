#pragma once

#include <QChart>
#include <QSplineSeries>
#include <QHBoxLayout>
#include <QValueAxis>
#include <QChartView>
#include <QWidget>
#include <vector>

class Chart
{
public:
    Chart(QWidget* widget, QString name);
    ~Chart();

    void Update(double x, double leftY, double rightY);
    void addSeries(std::vector<std::vector<double>> points, QColor color, QString name);
    void addDiscreteSeries(std::vector<std::vector<double>> points, QColor color, QString name);

private:
    QChart *_chart = nullptr;
    QChartView *_chartview = nullptr;
    QHBoxLayout *_layout = nullptr;
    QValueAxis *_axisX = nullptr;
    QValueAxis *_axisY = nullptr;
};
