#ifndef UNIFORMDISTRIBUTION_H
#define UNIFORMDISTRIBUTION_H

#include <random>
#include <QString>
#include <QVector>
#include <ctime>
#include <chrono>

/*
 * ����� ��� ��������� ��������� ����� uniform �������
 */
class UniformDistribution
{
public:
    // ����������� ������
    UniformDistribution(double x, double a, int n = 1000);

    QVector<double> getOutput();        // ����� ��� ������

	// ������ ��� ��������� ���������������� ��������
    void setX(double x);
    void setA(double a);

    long calculate(bool isNegative);    // �����, ������������ ������

private:

    QVector<double> output;     // ������ ����������� ���������

    int n;          // ����� ������������ ��������
    double x;       // �������� X (�����, �� ����� ������� ��� ���)
    double a;       // �������� A - ��������� (��� ��)
};

#endif // UNIFORMDISTRIBUTION_H
