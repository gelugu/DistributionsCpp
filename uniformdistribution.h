#ifndef UNIFORMDISTRIBUTION_H
#define UNIFORMDISTRIBUTION_H

#include <random>
#include <QString>
#include <QVector>
#include <ctime>
#include <chrono>

/*
 *  ласс дл€ генерации случайных чисел uniform методом
 */
class UniformDistribution
{
public:
    // конструктор класса
    UniformDistribution(double x, double a, int n = 1000);

    QVector<double> getOutput();        // метод дл€ вывода

	// методы дл€ установки пользовательских значений
    void setX(double x);
    void setA(double a);

    long calculate(bool isNegative);    // метод, производ€щий расчЄт

private:

    QVector<double> output;     // массив расчитанных элементов

    int n;          // число генерируемых значений
    double x;       // параметр X (думаю, “ы лучше опишешь что это)
    double a;       // параметр A - амплитуда (так же)
};

#endif // UNIFORMDISTRIBUTION_H
