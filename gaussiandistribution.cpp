#include "gaussiandistribution.h"
/*
 * в конструктор мы передаём обязательно ключевые параметры для генерации МО и сигма
 * и (необязательно) число значений (если не передаём - по умолчанию 1000)
 * и присваиваем их локальным полям класса
 */
GaussianDistribution::GaussianDistribution(double E, double sigma, int n)
{
    this->sigma = sigma;
    this->E = E;
    this->n = n;
}

// возвращает массив значений
QVector<double> GaussianDistribution::getOutput() { return output; }

// сеттеры (установщики) для значений
void GaussianDistribution::setSigma(double sigma) { this->sigma = sigma; }
void GaussianDistribution::setE(double E) { this->E = E; }

// метод, генерирующий значения
// принимает в себя параметр, отвечающий за необходимость генерации отрицательных чисел
long GaussianDistribution::calculate(bool isNegative)
{
    // переменные для расчёта времени алгоритма
    long start_time, end_time;

    // чистим текущий массив
    this->output.clear();

    /*
     * cоздаеv объект normal_distribution,
     * принимая параметры распределения, заданные либо посредством МО (E) и сигма.
     * генератор случайных чисел (gen) основывваем на текущем времени
     */
    std::default_random_engine gen((unsigned int)std::chrono::system_clock::now().time_since_epoch().count());
    std::normal_distribution<double> dis(this->E, this->sigma);

    start_time = clock(); // начальное время

    // если галочка (отрицательне) стоит, значит выполняем цикл под if
    if (isNegative)
    for(int i = 0; i < this->n/2; ++i)
    {
        // используем dis для преобразования из in в doubleв диапазоне [-σ, σ]
        // каждый вызов dis(gen) генерируется новое случайное double значение
        output.push_back(-round(dis(gen)*100)/100);
    }

    /*
     * (isNegative ? n/2 : n) - поясняю
     * если isNegative - true (нажата), то подставляем вместо всего этого выражения n/2
     * то есть получится "...; i < n/2;..."
     * если false (не нажата) то "...; i < n;..."
     */
    for(int i = 0; i < (isNegative ? n/2 : n); ++i)
    {
        output.push_back(round(dis(gen)*100)/100);
    }

    end_time = clock(); // конечное время

    return end_time - start_time; // искомое время
}
