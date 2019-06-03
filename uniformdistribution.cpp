#include "uniformdistribution.h"

/*
 * в конструктор мы передаём обязательно ключевые параметры для генерации X и A
 * и (необязательно) число значений (если не передаём - по умолчанию 1000)
 * и присваиваем их локальным полям класса
 */
UniformDistribution::UniformDistribution(double x, double a, int n)
{
    this->x = x;
    this->a = a;
    this->n = n;
}

// возвращает массив значений
QVector<double> UniformDistribution::getOutput() { return output; }

// сеттеры (установщики) для значений
void UniformDistribution::setX(double x) { this->x = x; }
void UniformDistribution::setA(double a) { this->a = a; }

// метод, генерирующий значения
// принимает в себя параметр, отвечающий за необходимость генерации отрицательных чисел
long UniformDistribution::calculate(bool isNegative)
{
    // переменные для расчёта времени алгоритма
    long start_time, end_time;

    // чистим текущий массив
    this->output.clear();

    /*
     * cоздаеv объект normal_distribution,
     * принимая параметры распределения, заданные посредством X и A.
     * генератор случайных чисел основывваем на текущем времени
     */
    std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<> dis(this->x, this->a);

    start_time = clock(); // начальное время

    // если галочка (отрицательне) стоит, значит выполняем цикл под if
    if (isNegative)
    for (int i = 0; i < n/2; i++) {
        // используем dis для преобразования из in в doubleв диапазоне [x, a)
        // каждый вызов dis(gen) генерируется новое случайное double значение
        this->output.push_back(-round(dis(gen)*100)/100);
    }
    /*
     * (isNegative ? n/2 : n) - поясняю
     * если isNegative - true (нажата), то подставляем вместо всего этого выражения n/2
     * то есть получится "...; i < n/2;..."
     * если false (не нажата) то "...; i < n;..."
     */
    for (int i = 0; i < (isNegative ? n/2 : n); i++) {
        this->output.push_back(round(dis(gen)*100)/100);
    }

    end_time = clock(); // конечное время

    return end_time - start_time; // искомое время
}
