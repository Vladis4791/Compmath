#include "model.h"

Model::Model(std::string fileName)
{
    std::ifstream dop_in(fileName);
    int count = 0;
    std::string addStr;
    while (getline(dop_in , addStr)) {
        count++;
    }
    std::ifstream in(fileName);
    if (in.is_open())
    {
        for (int i = 0; i < count; i++) {
            double xx, yy;
            in >> xx >> yy;
            x.push_back(xx); y.push_back(yy);
            points.push_back({xx, yy});
        }
    }
    in.close();

    Calc();
}

Model::Model(std::vector<double> x, std::vector<double> y)
    : x(x)
    , y(y)
{
    Calc();
}

void Model::Calc() {
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> b;
    A.resize(5);
    b.resize(5);
    for(int i = 0; i < 5; i++)
    {
        A[i].resize(5, 0);
        b[i].resize(1, 0);
    }

    for(size_t i = 0; i < x.size(); i++)
    {
        A[0][0] += pow(x[i], 2) * pow(y[i], 2);
        A[0][1] += pow(x[i], 1) * pow(y[i], 3);
        A[0][2] += pow(x[i], 2) * pow(y[i], 1);
        A[0][3] += pow(x[i], 1) * pow(y[i], 2);
        A[0][4] += pow(x[i], 1) * pow(y[i], 1);

        A[1][0] += pow(x[i], 1) * pow(y[i], 3);
        A[1][1] += pow(x[i], 0) * pow(y[i], 4);
        A[1][2] += pow(x[i], 1) * pow(y[i], 2);
        A[1][3] += pow(x[i], 0) * pow(y[i], 3);
        A[1][4] += pow(x[i], 0) * pow(y[i], 2);

        A[2][0] += pow(x[i], 2) * pow(y[i], 1);
        A[2][1] += pow(x[i], 1) * pow(y[i], 2);
        A[2][2] += pow(x[i], 2) * pow(y[i], 0);
        A[2][3] += pow(x[i], 1) * pow(y[i], 1);
        A[2][4] += pow(x[i], 1) * pow(y[i], 0);

        A[3][0] += pow(x[i], 1) * pow(y[i], 2);
        A[3][1] += pow(x[i], 0) * pow(y[i], 3);
        A[3][2] += pow(x[i], 1) * pow(y[i], 1);
        A[3][3] += pow(x[i], 0) * pow(y[i], 2);
        A[3][4] += pow(x[i], 0) * pow(y[i], 1);

        A[4][0] += pow(x[i], 1) * pow(y[i], 1);
        A[4][1] += pow(x[i], 0) * pow(y[i], 2);
        A[4][2] += pow(x[i], 1) * pow(y[i], 0);
        A[4][3] += pow(x[i], 0) * pow(y[i], 1);
        A[4][4] += 1;

        b[0][0] -= pow(x[i], 3) * pow(y[i], 1);
        b[1][0] -= pow(x[i], 2) * pow(y[i], 2);
        b[2][0] -= pow(x[i], 3) * pow(y[i], 0);
        b[3][0] -= pow(x[i], 2) * pow(y[i], 1);
        b[4][0] -= pow(x[i], 2) * pow(y[i], 0);
    }

    Matrix matrixA(A);
    matrixA.Inverse();
    Matrix matrixB(b);
    Matrix res = matrixA * matrixB;

    this->A = res.data[0][0];
    this->B = res.data[1][0];
    this->C = res.data[2][0];
    this->D = res.data[3][0];
    this->E = res.data[4][0];
}
