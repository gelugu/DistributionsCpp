#ifndef MATLABCREATOR_H
#define MATLABCREATOR_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDate>

/*
 * класс, который служит для создания файлов Matlab
 * имеет в себе единственный метод
 */
class MatlabCreator
{
public:
    // static показывает программе, что метод можно вызывать напрямую из класса без создания экземпляра
    // сам метод создаёт файл по !полному! пути и заполняет числами из массива v
    static void createFile(QString path, QVector<double> v);
};

#endif // MATLABCREATOR_H
