#ifndef GAUSSIANDISTRIBUTION_H
#define GAUSSIANDISTRIBUTION_H

#include <random>
#include <QString>
#include <QVector>
#include <ctime>
#include <chrono>

class GaussianDistribution
{
public:
    GaussianDistribution(double E, double sigma, int n = 1000);
    QVector<double> getOutput();

    void setSigma(double sigma);
    void setE(double E);

    long calculate(bool isNegative);

private:
    QVector<double> output;

    int n;

    double sigma;
    double E;
};

#endif // GAUSSIANDISTRIBUTION_H
